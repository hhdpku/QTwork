#include "adddiarydialog.h"
#include <QSlider>
#include <QLabel>
#include <QComboBox>
AddDiaryDialog::AddDiaryDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("添加日记");
    resize(500, 800);
    titleEdit = new QLineEdit(this);
    textEdit = new QTextEdit(this);

    moodSlider = new QSlider(Qt::Horizontal, this);
    moodSlider->setRange(0, 4);
    moodSlider->setValue(2); // 设置默认心情分数为2
    moodLabel = new QLabel("心情：普通", this);
    connect(moodSlider, &QSlider::valueChanged, this, &AddDiaryDialog::onMoodSliderValueChanged);
    weatherComboBox = new QComboBox(this);
    weatherComboBox->addItem("晴");
    weatherComboBox->addItem("多云");
    weatherComboBox->addItem("有风");
    weatherComboBox->addItem("雨");
    weatherComboBox->addItem("雪");
    QLabel *weatherLabel = new QLabel("今天天气如何？：", this);

    QPushButton *addButton = new QPushButton("添加", this);
    connect(addButton, &QPushButton::clicked, this, &AddDiaryDialog::onAddButtonClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleEdit);
    mainLayout->addWidget(weatherLabel);
    mainLayout->addWidget(weatherComboBox);
    mainLayout->addWidget(textEdit);
    mainLayout->addWidget(new QLabel("为您的心情打个分吧：", this));
    mainLayout->addWidget(moodLabel);
    mainLayout->addWidget(moodSlider);
    mainLayout->addWidget(addButton);
}
void AddDiaryDialog::onMoodSliderValueChanged(int value)
{
    QString moodText;
    switch(value) {
    case 0:
        moodText = "糟透了";
        break;
    case 1:
        moodText = "比较失落";
        break;
    case 2:
        moodText = "一般般";
        break;
    case 3:
        moodText = "不错";
        break;
    case 4:
        moodText = "很开心";
        break;
    }
    moodLabel->setText(moodText);
}

void AddDiaryDialog::onAddButtonClicked()
{
    QString title = titleEdit->text();
    QString text = textEdit->toPlainText();
    int mood = moodSlider->value();
    QString weather = weatherComboBox->currentText();
    emit diaryAdded(title, text,mood,weather);
    close();
}
