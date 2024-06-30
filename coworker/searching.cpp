#include "searching.h"
#include "ui_searching.h"
#include <QLabel>
#include <QPixmap>
#include<ALL.h>
#include <QVBoxLayout>
#include<func.h>
#include<QHBoxLayout>
#include <QScrollBar>
extern QMap<QString,Dairy>dairy;
Searching::Searching(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Searching)
{
    ui->setupUi(this);
    QLabel *searchIconLabel = new QLabel(this);
    diaryLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    diaryLayout->setSpacing(0);
    diaryLayout->setContentsMargins(0, 0, 0, 0);
    ui->scrollAreaWidgetContents->setLayout(diaryLayout);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &Searching::on_pushButton_2_clicked);
    // 加载搜索图标
    QPixmap searchIcon(":/image/R1.png");

    // 缩放图标大小
    QSize iconSize(20, 20); // 设置图标大小为 24x24 像素
    searchIcon = searchIcon.scaled(iconSize, Qt::KeepAspectRatio); // 缩放图标，并保持纵横比
    // 设置 QLabel 的图标
    searchIconLabel->setPixmap(searchIcon);
    // 设置 QLabel 的位置和大小
    searchIconLabel->setGeometry(10, 10, iconSize.width(), iconSize.height());
    // 可以添加其他初始化代码，如设置搜索框等
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Searching::on_pushButton_2_clicked);
}

Searching::~Searching()
{
    delete ui;
}

void Searching::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    clearSearchResults();
}


void Searching::on_pushButton_2_clicked()
{
    clearSearchResults();
    QString searchTerm = ui->lineEdit->text().trimmed(); // 获取搜索框中的文本并去除首尾空格
    std::vector<QString> searchResults = search1(searchTerm);
    QMap<QString, Dairy> filteredDairy;
    for(auto i=searchResults.begin();i<searchResults.end();i++){
        if (dairy.contains(*i)) {
            filteredDairy.insert(*i, dairy[*i]);
        }
    }
    QMapIterator<QString, Dairy> i(filteredDairy);
    while (i.hasNext()) {
        i.next();
        QString key = i.key();
        Dairy dairyEntry = i.value();

        QPushButton *button = new QPushButton(dairyEntry.title, ui->scrollAreaWidgetContents);
        button->setMinimumHeight(100); // 设置按钮最小高度为 100
        button->setMaximumHeight(400); // 设置按钮最大高度为 400
        button->setStyleSheet("margin: 0px; padding: 0px;font-size: 16px;"); // 去掉按钮的边距和填充

        // 连接按钮的点击信号到槽函数
        connect(button, &QPushButton::clicked, [this, key]() {
            // 在这里处理按钮点击后显示日记内容的逻辑
            emit diaryButtonClicked(key);
        });

        // 将按钮添加到布局中
        diaryLayout->addWidget(button);
    }

    ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->minimum());
}
void Searching::clearSearchResults()
{
    QLayout *layout = ui->scrollAreaWidgetContents->layout();
    if (layout) {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    }
}
