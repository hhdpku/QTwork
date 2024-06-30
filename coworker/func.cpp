#include<ALL.h>
#include<func.h>
#include<qstring>
#include<ctime>
#include<sstream>
#include<iomanip>
#include<QFile>
#include<QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include<QDebug>
#include<qstring>
#include<QRegularExpression>
extern std::vector< DDL>unfinished;//存储大的ddl(暂时不实现分成小的ddl)
extern QMap<QString,Dairy>dairy;//使用qmap可能有利于查找
extern QMap<QString, DDL>deadline;
extern QMap<QString, DDL>finished;
using namespace std;
QString gettime(){
    time_t now=time(nullptr);
    char time1[60]={};
    strftime(time1,sizeof(time1),"%Y%m%d%H%M",localtime(&now));
    return QString(time1);
}//获取当前时间，以年月日时分输出，如202405101320
time_t times(QString timestr){
    tm tm1={};
    std::string timestrstd=timestr.toStdString();
    std::istringstream ss(timestrstd);
    ss>>std::get_time(&tm1,"%Y%m%d%H%M");
    return mktime(&tm1);
}//可以理解为得到从1970年1月1日的秒数，输入格式同上
void DairyToFile(QMap<QString,Dairy>s,const QString& filename){
    QFile dairy1(filename);
    if(!dairy1.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"读取存档失败，请重新检查？";
    }
    else
    {
        qDebug()<<"恭喜你，打开文件成功！";
    }
    QTextStream qtextstreamwrite(&dairy1);
    for(auto i=s.begin();i!=s.end();i++){
        QString key = i.key(); // 获取QMap的key
        Dairy value = i.value(); // 获取QMap的value (Dairy对象)
        QString mood=QString::number(value.state);
        QString current1=value.current;
        QString text1=value.text;
        QString weather1=value.weather;
        text1.replace("\n", "\\n").replace("\"", "\\\"");
        QString title1=value.title;
        qtextstreamwrite << "\"" << current1 << "\",\"" << title1 << "\",\"" <<weather1<<"\",\"" << text1 << "\",\"" << mood << "\"\n";
    }
    dairy1.close();
}
void ddlToFile(QMap<QString, DDL> &s, const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "读取存档失败，请重新检查？";
        return;
    } else {
        qDebug() << "恭喜你，打开文件成功！";
    }

    QTextStream qtextstreamwrite(&file);
    for (auto i = s.begin(); i != s.end(); ++i) {
        DDL ddl1 = i.value();
        QString title1 = ddl1.title;
        QString time = ddl1.ddl; // 假设 `ddl` 是表示时间的 QString
        int state1 = ddl1.state;

        qtextstreamwrite << title1 << " " << time << " " << QString::number(state1) << "\n";
    }

    file.close();
}
//上面是写入文件涉及函数,输入容器名和文件名，将元素写入文件
void DairyFromFile(QMap<QString,Dairy>&s,const QString& filename){
    s.clear();
    QFile dairy1(filename);
    if (!dairy1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "读取文件失败，请重新检查？";
        return;
    } else {
        qDebug() << "文件打开成功！";
    }
    QTextStream qtextstreamread(&dairy1);
    static QRegularExpression regex("\"([^\"]*)\",\"([^\"]*)\",\"([^\"]*)\",\"([^\"]*)\",\"([^\"]*)\"");
    while (!qtextstreamread.atEnd()) {
        QString line = qtextstreamread.readLine();
        QRegularExpressionMatch match = regex.match(line);
        if (match.hasMatch()) {
            QString current = match.captured(1);
            QString title = match.captured(2);
            QString weather=match.captured(3);
            QString text = match.captured(4);
            text.replace("\\n", "\n").replace("\\\"", "\"");
            int mood = match.captured(5).toInt();
            Dairy dairy2(title,text,mood,current,weather); // 将后续部分合并为text
            s[title]=dairy2;
    }
    dairy1.close();
}
}
void ddlFromFile(QMap<QString, DDL> &s, const QString &filename) {
    s.clear();
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "读取文件失败，请重新检查？";
        return;
    } else {
        qDebug() << "文件打开成功！";
    }

    QTextStream qtextstreamread(&file);
    while (!qtextstreamread.atEnd()) {
        QString line = qtextstreamread.readLine();
        QStringList fields = line.split(' ', Qt::SkipEmptyParts);
        if (fields.size() >= 3) {
            QString title = fields[0];
            QString time = fields[1]; // 假设时间格式是字符串
            int state = fields[2].toInt(); // 假设状态是整数

            // 创建DDL对象并添加到map中
            DDL ddl(title ,"", time, state); // 根据实际的DDL构造函数进行调整
            s[title] = ddl;
        }
    }

    file.close();
}

//文件写入容器
std::vector<QString>search1(QString s1){
    std::vector<QString> results;

    // 遍历 QMap，查找匹配的标题
    for (auto it = dairy.begin(); it != dairy.end(); ++it) {
        const QString& title = it.key();
        //如果标题包含关键字 s1，则加入结果列表
        if (title.contains(s1, Qt::CaseInsensitive)) {
            results.push_back(title);
        }
    }

    return results;
}

