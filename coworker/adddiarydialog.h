#ifndef ADDDIARYDIALOG_H
#define ADDDIARYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSlider>
#include<QLabel>
#include <QComboBox>

class AddDiaryDialog : public QDialog
{
    Q_OBJECT

public:
    AddDiaryDialog(QWidget *parent = nullptr);

signals:
    void diaryAdded(const QString &title, const QString &text,int n,QString weather);
    inline void onMoodSliderValueChanged(int value);

private slots:
    void onAddButtonClicked();

private:
    QLineEdit *titleEdit;
    QTextEdit *textEdit;
    QSlider *moodSlider;
    QLabel *moodLabel;
    QComboBox *weatherComboBox;
};

#endif // ADDDIARYDIALOG_H
