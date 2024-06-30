#ifndef ALL_H
#define ALL_H
#include "qdatetime.h"
#include<qstring>
#include<QFile>
#include<vector>
#include<QMap>
class ALL{
public:
    QString title;//标题（ddl没有）
    QString text;//内容
    QString current;//时间
    ALL();
    ALL(QString s1,QString s2);
    ALL(QString s1,QString s2,QString s3);
};
class DDL:public ALL{
public:
    int id;//编号
    QString ddl;//截止时间
    int state;//重要程度
    int remindtime;//提前多久提醒
    bool hasremind;//是否被提醒过
    bool hasfinished;//是否已完成
    DDL();
    DDL(QString s1,QString s2,QString s3,int a);
    DDL(QString s1,QString s2,QString s3,int a,QString s4,int a1,int a2,int a3);
    void change(QString newddl,int newstate);//修改
    bool operator<(DDL &a);
    virtual void reminding();//提醒
    void deleting(int _id);//删除ddl
    void finishing(int _id);//将已完成的任务加入vector中
};
class YDBG:public ALL{
public:
    YDBG(){month=QDate::currentDate().month();};
    int month;
    int getunfinished(QMap<QString,DDL> &_unfinished);//获取未完成数量
    int getfinished(QMap<QString,DDL> &_finished);
    int getall(QMap<QString,DDL> &_ddl);
    QString showddl();
    bool gettime();
    int get20(int k);
    int get40(int k);
    int get60(int k);
    int get80(int k);
    int get100(int k);
    QDate rjdate(const QString &dateTimeString);
};
class Dairy:public ALL{
public:
    int state;//心情
    int _id;//编号
    QString weather;
    Dairy();
    Dairy(QString s1,QString s2,int n,QString s4);
    Dairy(QString s1,QString s2,int n,QString s3,QString s4);
    void deleting(int _id);
    void searchtitle(QString title);//搜索（暂时根据时间）
    void searchtime(QString time);//搜索（暂时根据时间）
    bool operator<(const Dairy &a);
};
class littleDDL:public DDL{
public:
    std::vector<DDL>subtasks;
    int finish_one;//已经完成到哪一个子任务
    littleDDL(QString& title,QString& content, QString& deadline,int a);
    void addSubTask(std::vector<DDL>subTask);//加入小任务,只在剩1或2天提醒
    void reminding();//小ddl的提醒功能，虚函数以确保与父类提醒不同
    void finishing(int i);//已经完成第i个任务，更新finish_one
    void deleting(int _id);
};//细分的ddl
#endif // ALL_H
