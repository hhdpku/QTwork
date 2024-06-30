#ifndef MODIFYDDLDIALOG_H
#define MODIFYDDLDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QSlider>
#include <QDateTimeEdit>
#include <QPushButton>

class ModifyDDLDialog : public QDialog
{
    Q_OBJECT

public:
    ModifyDDLDialog(const QString &title, const QString &dueDate, int state, QWidget *parent = nullptr);

signals:
    void ddlModified(const QString &newTitle, const QString &newDueDate, int newState);

private slots:
    void onModifyButtonClicked();

private:
    QLineEdit *titleEdit;
    QDateTimeEdit *dueDateEdit;
    QSlider *stateSlider;
};

#endif // MODIFYDDLDIALOG_H
