#include "ddldialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QFormLayout>
#include <QDateTime>
#include <QPainter>
QDate DDLDialog::parseDate(const QString &dateTimeString) {
    // 将200511051235这种格式的字符串转换为QDate
    int year = dateTimeString.mid(0, 4).toInt();
    int month = dateTimeString.mid(4, 2).toInt();
    int day = dateTimeString.mid(6, 2).toInt();
    return QDate(year, month, day);
}

DDLDialog::DDLDialog(const QString &title, const QString &time, const int &state, QWidget *parent)
    : QDialog(parent), title(title)
{
    setWindowTitle("查看deadline");
    resize(400, 700);  // 调整窗口大小
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setFixedSize(580, 700);

    QDate dueDate = parseDate(time);
    QString formattedDate = dueDate.toString("yyyy年M月d日");

    textEdit->setHtml(QString("<div>"
                              "<h1 style='font-size:36px;'>%1</h1>"
                              "<p style='font-size:16px;'>截止时间: %2</p>"
                              "<p style='font-size:14px;'>重要程度: %3</p>"
                              "</div>").arg(title, formattedDate, QString::number(state)));

    modifyButton = new QPushButton("修改", this);
    deleteButton = new QPushButton("删除", this);
    markAsCompleteButton = new QPushButton("标记为已完成", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(textEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(modifyButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(markAsCompleteButton);
    mainLayout->addLayout(buttonLayout);

    connect(modifyButton, &QPushButton::clicked, this, &DDLDialog::onModifyButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &DDLDialog::onDeleteButtonClicked);
    connect(markAsCompleteButton, &QPushButton::clicked, this, &DDLDialog::onMarkAsCompleteButtonClicked);
}
void DDLDialog::paintEvent(QPaintEvent *event)
{
    // 绘制背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/image/OIP.jpg")); // 替换成你的背景图片路径
}
void DDLDialog::onModifyButtonClicked()
{
    emit modifyRequested(title);
    close();
}

void DDLDialog::onDeleteButtonClicked()
{
    emit deleteRequested(title);
    close();
}

void DDLDialog::onMarkAsCompleteButtonClicked() {
    emit markAsCompleteRequested(title);
    close();
}
