#include "diarydiolog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QFormLayout>
#include<modify.h>
#include <QDateTime>
#include <QPainter>
QDate DiaryDialog::parseDate(const QString &dateTimeString) {
    // 将200511051235这种格式的字符串转换为QDate
    int year = dateTimeString.mid(0, 4).toInt();
    int month = dateTimeString.mid(4, 2).toInt();
    int day = dateTimeString.mid(6, 2).toInt();
    return QDate(year, month, day);
}
DiaryDialog::DiaryDialog(const QString &title, const QString &text,const QString &date, const QString weather,QWidget *parent)
    : QDialog(parent), title(title)
{
    setWindowTitle("查看日记");
    resize(300, 600);  // 调整窗口大小
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setFixedSize(400, 600);
    QDate dating = parseDate(date);
    QString formattedDate = dating.toString("yyyy年M月d日")+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天气:"+weather;
    QString htmlText = text;
    htmlText.replace("\n", "<br>");
    textEdit->setHtml(QString("<div>"
                              "<h1 style='font-size:36px;'>%1</h1>"
                              "<p style='font-size:14px; color:gray;'>%2</p>"
                              "<p style='font-size:16px;'>%3</p>"
                              "</div>").arg(title,formattedDate,htmlText));

    modifyButton = new QPushButton("修改", this);
    deleteButton = new QPushButton("删除", this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(textEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(modifyButton);
    buttonLayout->addWidget(deleteButton);
    mainLayout->addLayout(buttonLayout);
    connect(modifyButton, &QPushButton::clicked, this, &DiaryDialog::onModifyButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &DiaryDialog::onDeleteButtonClicked);
}
void DiaryDialog::paintEvent(QPaintEvent *event)
{
    // 绘制背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/image/OIP.jpg")); // 替换成你的背景图片路径
}
void DiaryDialog::onModifyButtonClicked()
{
    emit modifyRequested(title);
    close();
}

void DiaryDialog::onDeleteButtonClicked()
{
    emit deleteRequested(title);
    close();
}
