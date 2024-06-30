#ifndef FUNC_H
#define FUNC_H
#include<qstring>
#include<ctime>
#include<ALL.h>
#include<QFile>
#include<QMap>
#include<qstring>
QString gettime();
time_t times(QString timestr);
void DairyToFile(QMap<QString,Dairy>s,const QString& filename);
void ddlToFile(QMap<QString, DDL> &s, const QString& filename);//deadline
//存储至文件功能
void DairyFromFile(QMap<QString,Dairy>&s,const QString& filename);
void ddlFromFile(QMap<QString, DDL>&s,const QString& filename);
std::vector<QString>search1(QString s);
//文件到vector中
#endif // FUNC_H
