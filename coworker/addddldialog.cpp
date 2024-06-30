#include "addddldialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateTimeEdit>

AddDDLDialog::AddDDLDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("添加deadline");
    resize(500, 300);

    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("输入标题");

    dueDateEdit = new QDateTimeEdit(this);
    dueDateEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    dueDateEdit->setDateTime(QDateTime::currentDateTime()); // 设置初始值为当前时间

    stateSlider = new QSlider(Qt::Horizontal, this);
    stateSlider->setRange(1, 5);
    stateSlider->setValue(3); // 设置默认重要程度为3
    stateLabel = new QLabel(QString::number(3), this);
    connect(stateSlider, &QSlider::valueChanged, stateLabel, QOverload<int>::of(&QLabel::setNum));

    QPushButton *addButton = new QPushButton("添加", this);
    connect(addButton, &QPushButton::clicked, this, &AddDDLDialog::onAddButtonClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleEdit);
    mainLayout->addWidget(dueDateEdit);
    mainLayout->addWidget(new QLabel("设置重要程度", this));
    mainLayout->addWidget(stateLabel);
    mainLayout->addWidget(stateSlider);
    mainLayout->addWidget(addButton);
}

void AddDDLDialog::onAddButtonClicked()
{
    QString title = titleEdit->text();
    QString dueDate = dueDateEdit->dateTime().toString("yyyyMMddHHmm");
    int state = stateSlider->value();
    emit ddlAdded(title, dueDate, state);
    close();
}

void AddDDLDialog::onStateSliderValueChanged(int value){
    QString stateText;
    switch(value) {
    case 1:
        stateText = "糟透了";
        break;
    case 2:
        stateText = "比较失落";
        break;
    case 3:
        stateText = "一般般";
        break;
    case 4:
        stateText = "不错";
        break;
    case 5:
        stateText = "很开心";
        break;
    }
    stateLabel->setText(stateText);
}
