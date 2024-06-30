#ifndef ADDDDLDIALOG_H
#define ADDDDLDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QSlider>
#include <QLabel>
#include <QDateTimeEdit>
#include <QPushButton>

class AddDDLDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDDLDialog(QWidget *parent = nullptr);

signals:
    void ddlAdded(const QString &title, const QString &dueDate, int state);
    inline void onStateSliderValueChanged(int value);


private slots:
    void onAddButtonClicked();

private:
    QLineEdit *titleEdit;
    QDateTimeEdit *dueDateEdit;
    QSlider *stateSlider;
    QPushButton *addButton;
    QLabel *stateLabel;
};

#endif // ADDDDLDIALOG_H
