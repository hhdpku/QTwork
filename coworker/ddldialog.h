#ifndef DDLDIALOG_H
#define DDLDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include<ALL.h>
class DDLDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DDLDialog(const QString &title, const QString &time, const int &state,  QWidget *parent = nullptr);
    QDate parseDate(const QString &dateTimeString);
    void paintEvent(QPaintEvent *event);
signals:
    void modifyRequested(const QString &title);
    void deleteRequested(const QString &title);
    void markAsCompleteRequested(const QString &title);

private slots:
    void onModifyButtonClicked();
    void onDeleteButtonClicked();
    void onMarkAsCompleteButtonClicked();


private:
    QString title;
    QLineEdit *titleEdit;
    QTextEdit *textEdit;
    QPushButton *modifyButton;
    QPushButton *deleteButton;
    QPushButton *markAsCompleteButton;

};

#endif // DDLDIALOG_H
