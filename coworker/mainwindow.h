#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include<QVBoxLayout>
#include <QScrollBar>
#include "modify.h"
#include "yuedubaogao.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton *button;

private slots:
    void onDiaryButtonClicked();
    void paintEvent(QPaintEvent *event);
    void onModifyRequested(const QString &title);
    void onDeleteRequested(const QString &title);
    void on_adddiary_clicked();
    void addDiary(const QString &title, const QString &text,int state,QString weather);

    void onDDLButtonClicked();
    void onDeleteRequested1(const QString &title);
    void on_addddl_clicked();
    void addDDL(const QString &title, const QString &time,int state);
    void onDDLModified(const QString &oldTitle, const QString &newTitle, const QString &newDueDate, int newState);
    void onMarkAsCompleteRequested(const QString &title);
    void onTimeout(); // 声明槽函数

    void on_pushButton_clicked();
    void onSearchDiaryButtonClicked(const QString &title);
    void on_month_clicked();

private:
    Ui::MainWindow *ui;
    void populateDiaryButtons();
    QVBoxLayout *diaryLayout;
    Modify *modifyDialog;    // 声明 diaryLayout

    void populateDDLButtons();
    QVBoxLayout *ddlLayout;
    Modify *modifyDialog1;
    QTimer *reminderTimer;
    void remindDDLs();
    void check();
    yuedubaogao *ydbg;
};

#endif // MAINWINDOW_H

