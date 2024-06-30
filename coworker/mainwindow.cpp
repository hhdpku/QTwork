#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<diarydiolog.h>
#include<QVBoxLayout>
#include<ALL.h>
#include<func.h>
#include<QFile>
#include<QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include<adddiarydialog.h>
#include "modify.h"
#include "ui_modify.h"
#include <addddldialog.h>
#include <ddldialog.h>
#include <modifyddldialog.h>
#include "searching.h"
#include <QTimer>
#include<QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include<yuedubaogao.h>
#include <cstdlib>
extern QMap<QString, DDL>unfinished;//存储大的ddl(暂时不实现分成小的ddl)
extern QMap<QString,Dairy>dairy;//使用qmap可能有利于查找
extern QMap<QString, DDL>deadline;
extern QMap<QString, DDL>finished;
std::vector<QString>word1={"这一切都会过去，相信明天会更好。","你的坚强将克服一切困难。","每一次挑战都是成长的机会。","你有足够的力量战胜眼前的一切。","坚持下去，你会发现内心的力量。","今天的阴霾，会被明天的阳光驱散。","在每一个低谷，都蕴藏着向上的力量。","你的勇气比你想象的更加强大。","让自己放松一下，事情会慢慢好起来的。","你的努力和耐心会迎来美好的改变。"};//心情比较差
std::vector<QString>word2={"你的积极态度是你最大的资产，继续保持，将它发挥到极致！","让心情的阳光继续灿烂，因为你的笑容是最美的风景。""心情愉快是一种选择，让快乐成为你的习惯，继续保持，享受每一天的阳光。""每一次微笑都是对生活的一次胜利，继续保持，让微笑成为你最好的陪伴。","在每一个美好的瞬间，都让笑容绽放，继续保持，向着幸福前行。"};//心情比较好
YDBG monthbg;
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/image/view.jpg"));
}
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建一个垂直布局

    diaryLayout = new QVBoxLayout();
    diaryLayout->setSpacing(0);
    diaryLayout->setContentsMargins(0, 0, 0, 0);
    QPushButton *button = findChild<QPushButton*>("month");
    button->setText("查\n看\n我\n的\n月\n度\n报\n告");

    // 创建一个滚动区域
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *container = new QWidget;
    container->setLayout(diaryLayout);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);

    // 将滚动区域添加到主窗口布局中
    ui->diaryscroll->setWidget(scrollArea);

    // 填充日记按钮
    populateDiaryButtons();

    ddlLayout = new QVBoxLayout();
    ddlLayout->setSpacing(0);
    ddlLayout->setContentsMargins(0, 0, 0, 0);

    QScrollArea *scrollArea1 = new QScrollArea(this);
    QWidget *container1 = new QWidget;
    container1->setLayout(ddlLayout);
    scrollArea1->setWidget(container1);
    scrollArea1->setWidgetResizable(true);

    // 将滚动区域添加到主窗口布局中
    ui->ddlscroll->setWidget(scrollArea1);

    // 填充deadline按钮
    populateDDLButtons();
    reminderTimer = new QTimer(this);
    reminderTimer->setSingleShot(true);
    reminderTimer->setInterval(500); // 500毫秒延迟

    // 将 QTimer 的 timeout 信号连接到提醒函数的槽函数
    connect(reminderTimer, &QTimer::timeout, this, &MainWindow::onTimeout);

    // 启动 QTimer，使其在一段时间后触发 timeout 信号
    reminderTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateDiaryButtons()
{
    // 清空当前布局中的所有控件
    QLayoutItem *item;
    while ((item = diaryLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // 遍历 dairy 并为每个元素创建一个按钮
    QMapIterator<QString, Dairy> i(dairy);
    while (i.hasNext()) {
        i.next();
        QString key = i.key();
        Dairy dairyEntry = i.value();
        // 创建按钮并设置名字
        QPushButton *button = new QPushButton(dairyEntry.title, this);
        button->setMinimumHeight(100); // 设置按钮最小高度为 100
        button->setMaximumHeight(400); // 设置按钮最大高度为 400
        button->setStyleSheet("margin: 0px; padding: 0px;font-size: 16px;"); // 去掉按钮的边距和填充
        // 连接按钮的点击信号到槽函数
        connect(button, &QPushButton::clicked, this, &MainWindow::onDiaryButtonClicked);

        // 将按钮添加到布局中
        diaryLayout->addWidget(button);
    }
    ui->diaryscroll->verticalScrollBar()->setValue(ui->diaryscroll->verticalScrollBar()->minimum());
}
void MainWindow::onDiaryButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button) {
        QString title = button->text();
        if (dairy.contains(title)) {
            // 创建 DiaryDialog 对象并连接 modifyRequested 信号

            DiaryDialog dialog(dairy[title].title, dairy[title].text,dairy[title].current,dairy[title].weather, this);
            connect(&dialog, &DiaryDialog::modifyRequested, this, [=](const QString &title) {
                // 在 modifyRequested 信号触发时创建并显示 Modify 对话框
                Modify *modifyDialog = new Modify(this);
                modifyDialog->ui->lineEdit->setText(dairy[title].title);
                modifyDialog->ui->textEdit->setText(dairy[title].text);

                // 连接 Modify 对话框的 accepted() 信号，处理用户确认修改后的逻辑
                connect(modifyDialog, &QDialog::accepted, this, [=]() {
                    QString newTitle = modifyDialog->ui->lineEdit->text();
                    QString newText = modifyDialog->ui->textEdit->toPlainText();

                    if (!newText.isEmpty() || !newTitle.isEmpty()) {
                        // 更新数据结构中的文本内容和标题
                        dairy[newTitle] = dairy[title];
                        // 删除旧的键值对
                        dairy.remove(title);

                        // 更新新键值对的文本内容和标题
                        dairy[newTitle].text = newText;
                        dairy[newTitle].title = newTitle;
                        DairyToFile(dairy, "D:/dairy.txt");
                        populateDiaryButtons(); // 更新显示
                    }

                    delete modifyDialog; // 在处理完毕后删除 Modify 对象
                });

                modifyDialog->exec(); // 显示 Modify 对话框
            });

            // 连接删除请求信号
            connect(&dialog, &DiaryDialog::deleteRequested, this, &MainWindow::onDeleteRequested);
            dialog.exec(); // 显示 DiaryDialog
        }
    }
}
void MainWindow::onModifyRequested(const QString &title)
{
    if (dairy.contains(title)) {
        Modify modifyDialog(this);
        modifyDialog.ui->lineEdit->setText(dairy[title].title);
        modifyDialog.ui->textEdit->setText(dairy[title].text);
    }
    if (modifyDialog->exec() == QDialog::Accepted) {
        // 获取用户输入的新标题和新内容
        QString newTitle = modifyDialog->ui->lineEdit->text();
        QString newText = modifyDialog->ui->textEdit->toPlainText();

        if (!newText.isEmpty() || !newTitle.isEmpty()) {
            // 更新数据结构中的文本内容和标题
            dairy[newTitle] = dairy[title];
            // 删除旧的键值对
            dairy.remove(title);

            // 更新新键值对的文本内容和标题
            dairy[newTitle].text = newText;
            dairy[newTitle].title = newTitle;
            DairyToFile(dairy, "D:/dairy.txt");
            populateDiaryButtons(); // 更新显示
        }
    }
}

void MainWindow::onDeleteRequested(const QString &title)
{
    if (dairy.contains(title)) {
        int ret = QMessageBox::warning(this, "删除日记", "确认要删除吗?", QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes) {
            dairy.remove(title);
            DairyToFile(dairy,"D:/dairy.txt");
            populateDiaryButtons(); // 更新显示
        }
    }
}
void MainWindow::on_adddiary_clicked()
{
    AddDiaryDialog dialog(this);
    connect(&dialog, &AddDiaryDialog::diaryAdded, this, &MainWindow::addDiary);
    dialog.exec();
}
void MainWindow::addDiary(const QString &title, const QString &text,int state,QString weather)
{
    // 将标题和内容添加到 dairy 中
    Dairy newDairy(title,text,state,weather);
    dairy[title] = newDairy;
    DairyToFile(dairy,"D:/dairy.txt");
    // 更新日记按钮
    populateDiaryButtons();
}

void MainWindow::populateDDLButtons()
{
    // 清空当前布局中的所有控件
    QLayoutItem *item;
    while ((item = ddlLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // 将DDL按截止日期排序
    QList<DDL> sortedDDLList = deadline.values();
    std::sort(sortedDDLList.begin(), sortedDDLList.end(), [](const DDL &a, const DDL &b) {
        QDateTime dateTimeA = QDateTime::fromString(a.ddl, "yyyyMMddHHmm");
        QDateTime dateTimeB = QDateTime::fromString(b.ddl, "yyyyMMddHHmm");
        return dateTimeA < dateTimeB;
    });

    // 遍历排序后的DDL并为每个元素创建一个按钮
    for (const DDL &ddlEntry : sortedDDLList) {
        // 计算剩余天数
        int daysLeft = QDateTime::currentDateTime().daysTo(QDateTime::fromString(ddlEntry.ddl, "yyyyMMddHHmm"));

        // 创建按钮并设置名字
        QPushButton *button = new QPushButton(this);
        button->setText(QString("%1\n%2 days left").arg(ddlEntry.title).arg(daysLeft)); // 显示标题和剩余天数
        button->setProperty("title", ddlEntry.title); // 存储标题

        button->setMinimumHeight(100); // 设置按钮最小高度为 100
        button->setMaximumHeight(400); // 设置按钮最大高度为 400
        button->setStyleSheet("margin: 0px; padding: 0px;font-size: 16px;"); // 去掉按钮的边距和填充

        // 连接按钮的点击信号到槽函数
        connect(button, &QPushButton::clicked, this, &MainWindow::onDDLButtonClicked);

        // 将按钮添加到布局中
        ddlLayout->addWidget(button);
    }
    ui->ddlscroll->verticalScrollBar()->setValue(ui->ddlscroll->verticalScrollBar()->minimum());
}
void MainWindow::onDDLButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button) {
        QString title = button->property("title").toString();
        if (deadline.contains(title)) {
            // 创建 DDLDialog 对象并连接 modifyRequested 信号
            DDLDialog dialog(deadline[title].title,deadline[title].ddl,deadline[title].state, this);
            dialog.setFixedSize(300, 200);
            connect(&dialog, &DDLDialog::modifyRequested, this, [=](const QString &title) {
                // 在 modifyRequested 信号触发时创建并显示 Modify 对话框
                ModifyDDLDialog *modifyDialog = new ModifyDDLDialog(deadline[title].title,deadline[title].ddl,deadline[title].state, this);
                connect(modifyDialog, &ModifyDDLDialog::ddlModified, this, [=](const QString &newTitle, const QString &newDueDate, int newState) {
                    onDDLModified(title, newTitle, newDueDate, newState);
                });


                modifyDialog->exec(); // 显示 Modify 对话框
            });

            // 连接删除请求信号
            connect(&dialog, &DDLDialog::deleteRequested, this, &MainWindow::onDeleteRequested1);
            connect(&dialog, &DDLDialog::markAsCompleteRequested, this, &MainWindow::onMarkAsCompleteRequested);
            dialog.exec(); // 显示 DDLDialog
        }
    }
}

void MainWindow::onDDLModified(const QString &oldTitle, const QString &newTitle, const QString &newDueDate, int newState)
{
    if (!deadline.contains(oldTitle))
        return;

    DDL &ddl1 = deadline[oldTitle];
    ddl1.title = newTitle;
    ddl1.ddl = newDueDate;
    ddl1.state = newState;

    if (oldTitle != newTitle) {
        deadline.remove(oldTitle);
        deadline[newTitle] = ddl1;
    }

    // 这里可以添加代码，将修改后的 DDL 保存到文件或更新显示
    ddlToFile(deadline, "D:/deadline.txt");
    populateDDLButtons();
}


void MainWindow::onDeleteRequested1(const QString &title)
{
    if (deadline.contains(title)) {
        int ret = QMessageBox::warning(this, "删除deadline", "确认要删除吗?", QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes) {
            deadline.remove(title);
            ddlToFile(deadline,"D:/deadline.txt");
            populateDDLButtons(); // 更新显示
        }
    }
}

void MainWindow::onMarkAsCompleteRequested(const QString &title)
{
    if (deadline.contains(title)) {
        DDL completedDDL = deadline.take(title);  // 从未完成的DDL中移除

        // 假设你有一个已完成的DDL列表
        finished[title] = completedDDL;  // 将其添加到已完成的列表中
        ddlToFile(finished, "D:/finished.txt");
        ddlToFile(deadline, "D:/deadline.txt");  // 保存更新后的DDL到文件
        populateDDLButtons();  // 刷新界面
    }
}

void MainWindow::remindDDLs() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QList<QString> reminders;

    // 遍历所有 DDL
    QMapIterator<QString, DDL> i(deadline);
    while (i.hasNext()) {
        i.next();
        DDL ddl1 = i.value();

        // 将 QString 格式的时间转换为 QDateTime
        QDateTime deadline1 = QDateTime::fromString(ddl1.ddl, "yyyyMMddHHmm");

        // 计算从现在到截止时间的总时长，以秒为单位
        qint64 totalTimeInSeconds = currentTime.secsTo(deadline1);

        // 如果截止时间已经过去，不需要提醒
        if (totalTimeInSeconds <= 0) {
            continue;
        }

        // 计算提醒时间（提前 1 + state 天）
        int remindDays = 1 + ddl1.state;
        QDateTime remindTime = deadline1.addDays(-remindDays);

        // 如果当前时间超过提醒时间，并且没有提醒过，将标题和截止时间添加到提醒列表
        if (currentTime >= remindTime) {
            QString reminderText = QString("任务: %1\n截止时间: %2\n\n")
                                       .arg(ddl1.title)
                                       .arg(deadline1.toString("yyyy-MM-dd HH:mm"));
            reminders.append(reminderText);

            // 标记为已提醒
        }
    }

    // 如果有提醒需要显示，则显示提醒对话框
    if (!reminders.isEmpty()) {
        QString allReminders = reminders.join("\n");
        QMessageBox::information(this, "DDL提醒", allReminders);
    }
}


void MainWindow::onTimeout()
{
    // 在此处调用提醒函数，延迟显示提醒对话框
    remindDDLs();
    check();
}


void MainWindow::on_pushButton_clicked()
{
    // 创建搜索界面的实例
    Searching *searchingDialog = new Searching();
    setWindowTitle("search");
    connect(searchingDialog, &Searching::diaryButtonClicked, this, &MainWindow::onSearchDiaryButtonClicked);
    // 显示搜索界面
    searchingDialog->show();
}

void MainWindow::onSearchDiaryButtonClicked(const QString &title)
{
    if (dairy.contains(title)) {
        DiaryDialog *dialog = new DiaryDialog(dairy[title].title, dairy[title].text, dairy[title].current, dairy[title].weather, this);

        connect(dialog, &DiaryDialog::modifyRequested, this, [=](const QString &title) {
            Modify *modifyDialog = new Modify(this);
            modifyDialog->ui->lineEdit->setText(dairy[title].title);
            modifyDialog->ui->textEdit->setText(dairy[title].text);

            connect(modifyDialog, &QDialog::accepted, this, [=]() {
                QString newTitle = modifyDialog->ui->lineEdit->text();
                QString newText = modifyDialog->ui->textEdit->toPlainText();

                if (!newText.isEmpty() || !newTitle.isEmpty()) {
                    dairy[title].text = newText;
                    dairy[title].title = newTitle;
                    DairyToFile(dairy, "D:/dairy.txt");
                    populateDiaryButtons();
                }

                delete modifyDialog;
            });

            modifyDialog->exec();
        });

        connect(dialog, &DiaryDialog::deleteRequested, this, &MainWindow::onDeleteRequested);

        dialog->exec(); // 显示 DiaryDialog
    }
}

void MainWindow::on_addddl_clicked()
{
    qDebug() << "Add DDL button clicked";
    AddDDLDialog dialog(this);
    connect(&dialog, &AddDDLDialog::ddlAdded, this, &MainWindow::addDDL);
    dialog.exec();
}
void MainWindow::addDDL(const QString &title, const QString &time,int state)
{
    // 将标题和内容添加到 ddl 中
    qDebug() << "Adding DDL:" << title << time << state;
    DDL newDDL{title,"",time,state};
    deadline[title] = newDDL;
    ddlToFile(deadline,"D:/deadline.txt");
    // 更新日deadline按钮
    populateDDLButtons();
}

void MainWindow::check() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString expiredDDLMessage = "您有deadline已过期：\n";

    // 遍历所有 DDL
    QMapIterator<QString, DDL> i(deadline);
    bool hasExpiredDDL = false;  // 标记是否有过期的DDL
    while (i.hasNext()) {
        i.next();
        DDL ddl1 = i.value();

        // 将 QString 格式的时间转换为 QDateTime
        QDateTime deadline1 = QDateTime::fromString(ddl1.ddl, "yyyyMMddHHmm");

        // 计算从现在到截止时间的总时长，以秒为单位
        qint64 totalTimeInSeconds = currentTime.secsTo(deadline1);

        if (totalTimeInSeconds <= 0) {
            unfinished[ddl1.title] = deadline.take(ddl1.title);
            expiredDDLMessage += QString("标题: %1\n已截止于: %2\n\n").arg(ddl1.title, deadline1.toString("yyyy-MM-dd HH:mm"));
            hasExpiredDDL = true;
        }
    }

    ddlToFile(deadline, "D:/deadline.txt");
    ddlToFile(unfinished, "D:/unfinished.txt");

    // 如果有过期的DDL，显示提醒对话框
    if (hasExpiredDDL) {
        QMessageBox::warning(nullptr, "过期提醒", expiredDDLMessage);
    }
}

void MainWindow::on_month_clicked()
{


        // 创建一个新的窗口实例
        QMainWindow *newWindow = new QMainWindow();

        // 设置新窗口的大小为比当前窗口大一点，例如增加宽度和高度
        newWindow->resize(this->width() + 100, this->height() + 100);

        // 创建一个垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout();

        // 添加一个 QLabel 显示标题
        QLabel *titleLabel = new QLabel("月度报告");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setFont(QFont("Arial", 18, QFont::Bold));
        layout->addWidget(titleLabel);

        // 添加一个 QLabel 显示文本消息
        QLabel *messageLabel = new QLabel("请查收你的月度报告");
        messageLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(messageLabel);

        // 添加其他语句的 QLabel
        QLabel *statement1Label = new QLabel(monthbg.showddl());
        statement1Label->setAlignment(Qt::AlignCenter);
        layout->addWidget(statement1Label);

        // 创建一个五参数饼状图，并添加到新窗口中
        int a1 = monthbg.get20(QDate::currentDate().month());
        int a2 = monthbg.get40(QDate::currentDate().month());
        int a3 = monthbg.get60(QDate::currentDate().month());
        int a4 = monthbg.get80(QDate::currentDate().month());
        int a5 = monthbg.get100(QDate::currentDate().month());
        int sum = a1 + a2 + a3 + a4 + a5;

        double param1 = (sum != 0) ? double(100 * a1) / sum : 0;
        double param2 = (sum != 0) ? double(100 * a2) / sum : 0;
        double param3 = (sum != 0) ? double(100 * a3) / sum : 0;
        double param4 = (sum != 0) ? double(100 * a4) / sum : 0;
        double param5 = (sum != 0) ? 100 - param1 - param2 - param3 - param4 : 0;

        QPieSeries *series = new QPieSeries();
        series->append("心情糟糕", param1);
        series->append("心情不好", param2);
        series->append("心情还行", param3);
        series->append("心情不错", param4);
        series->append("心情很好", param5);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("心情饼状图");

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        layout->addWidget(chartView);
        if(float(a2+2*a3+3*a4+4*a5)/float(sum)>2){
            srand(time(nullptr));
            QString selected_sentence = word1[rand() % word1.size()];
        QLabel *additionalLabel = new QLabel(selected_sentence);
        additionalLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(additionalLabel);
        }
        if(float(a2+2*a3+3*a4+4*a5)/float(sum)<=2){
            srand(time(nullptr));
            QString selected_sentence = word2[rand() % word2.size()];
            QLabel *additionalLabel = new QLabel(selected_sentence);
            additionalLabel->setAlignment(Qt::AlignCenter);
            layout->addWidget(additionalLabel);
        }
        //创建一个 QWidget 作为新窗口的中心部件，并设置布局管理器
        QWidget *centralWidget = new QWidget();
        centralWidget->setLayout(layout);
        newWindow->setCentralWidget(centralWidget);

        // 显示新窗口
        newWindow->show();

}

