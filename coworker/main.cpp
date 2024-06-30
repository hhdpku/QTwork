#include "mainwindow.h"
#include<ALL.h>
#include<QFile>
#include<func.h>
#include <QApplication>
#include"modify.h"
#include<Searching.h>
extern QMap<QString, DDL>unfinished;//存储大的ddl(暂时不实现分成小的ddl)
extern QMap<QString,Dairy>dairy;//使用qmap可能有利于查找
extern QMap<QString, DDL>deadline;
extern QMap<QString, DDL>finished;
extern QFile unfinished_file;
extern QFile finished_file;
extern QFile notebook_file;
extern QFile dairy_file;
extern QFile deadline_file;
int main(int argc, char *argv[])
{
    DairyFromFile(dairy,"D:/dairy.txt");
    ddlFromFile(deadline, "D:/deadline.txt");
    ddlFromFile(unfinished, "D:/unfinished.txt");
    ddlFromFile(finished, "D:/finished.txt");
    QApplication a(argc, argv);
    MainWindow s1;
    Modify s2;
    Searching s3;
    s1.show();
    return a.exec();
}
