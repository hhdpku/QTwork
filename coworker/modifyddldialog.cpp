#include "modifyddldialog.h"
#include <QVBoxLayout>
#include <QLabel>

ModifyDDLDialog::ModifyDDLDialog(const QString &title, const QString &dueDate, int state, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("修改deadline");
    resize(500, 300);

    titleEdit = new QLineEdit(this);
    titleEdit->setText(title);  // 设置初始标题

    dueDateEdit = new QDateTimeEdit(QDateTime::fromString(dueDate, "yyyyMMddHHmm"), this);
    dueDateEdit->setDisplayFormat("yyyy-MM-dd HH:mm"); // 设置显示格式

    stateSlider = new QSlider(Qt::Horizontal, this);
    stateSlider->setRange(1, 5);
    stateSlider->setValue(state); // 设置初始重要程度

    QLabel *stateLabel = new QLabel(QString::number(state), this);
    connect(stateSlider, &QSlider::valueChanged, stateLabel, QOverload<int>::of(&QLabel::setNum));

    QPushButton *modifyButton = new QPushButton("修改", this);
    connect(modifyButton, &QPushButton::clicked, this, &ModifyDDLDialog::onModifyButtonClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleEdit);
    mainLayout->addWidget(dueDateEdit);
    mainLayout->addWidget(new QLabel("设置重要程度", this));
    mainLayout->addWidget(stateLabel);
    mainLayout->addWidget(stateSlider);
    mainLayout->addWidget(modifyButton);
}

void ModifyDDLDialog::onModifyButtonClicked()
{
    QString newTitle = titleEdit->text();
    QString newDueDate = dueDateEdit->dateTime().toString("yyyyMMddHHmm");
    int newState = stateSlider->value();
    emit ddlModified(newTitle, newDueDate, newState);
    close();
}
