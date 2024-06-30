#ifndef DIARYDIOLOG_H
#define DIARYDIOLOG_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include<ALL.h>
class DiaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DiaryDialog(const QString &title, const QString &text,const QString &date,const QString weather, QWidget *parent = nullptr);
    QDate parseDate(const QString &dateTimeString);
    void paintEvent(QPaintEvent *event);
signals:
    void modifyRequested(const QString &title);
    void deleteRequested(const QString &title);
private slots:
    void onModifyButtonClicked();
    void onDeleteButtonClicked();

private:
    QString title;
    QLineEdit *titleEdit;
    QTextEdit *textEdit;
    QPushButton *modifyButton;
    QPushButton *deleteButton;
};

#endif // DIARYDIOLOG_H
