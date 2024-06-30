#include<ALL.h>
#include<func.h>
#include<vector>
#include<QFile>
#include <QTextStream>
#include<ctime>
#include<QMap>
#include<qstring>
QMap<QString, DDL>unfinished;//存储大的ddl(暂时不实现分成小的ddl)
QMap<QString,Dairy>dairy;//使用qmap可能有利于查找
QMap<QString, DDL>deadline;
QMap<QString, DDL>finished;
//上面是各个部分所需的vector
// QFile unfinished_file("D:/unfinished.txt");
// QFile finished_file("D:/finished.txt");
// QFile notebook_file("D:/notebook.txt");
// QFile dairy_file("D:/dairy.txt");
// QFile deadline_file("D:/deadline.txt");
//上面是各个部分对应文件
int id_note=0;
int id_ddl=0;
int id_dairy=0;
std::pair<int,QString> emotion[5]={std::make_pair(20,"糟透了"),std::make_pair(40,"比较失落"),std::make_pair(60,"一般般"),std::make_pair(80,"不错"),std::make_pair(100,"很开心")};
//一些变量
ALL::ALL(){}
ALL::ALL(QString s1,QString s2):title(s1),text(s2){
    current=gettime();
}
ALL::ALL(QString s1,QString s2,QString s3):title(s1),text(s2),current(s3){
}
//ALL父类部分
int YDBG::getunfinished(QMap<QString, DDL> &_unfinished) {
    int initialSize = _unfinished.size(); // 初始的元素个数
    return initialSize;
}
int YDBG::getfinished(QMap<QString, DDL> &_finished) {
    int initialSize = _finished.size(); // 初始的元素个数
    return initialSize;
}

QString YDBG::showddl(){
    int unfinishednum=getunfinished(unfinished);
    int finishednum=getfinished(finished);
    int allnum=unfinishednum+finishednum;
    int j=finishednum*100/allnum;
    if(j>=75){
        QString s="本月共有"+QString::number(allnum)+"个ddl，完成了"+QString::number(finishednum)+"个，完成率为"+QString::number(j)+"%,这个月表现得不错，下个月还要加油哦！";
        return s;
    }

    else if(j>=50&&j<75){
        QString s="本月共有"+QString::number(allnum)+"个ddl，完成了"+QString::number(finishednum)+"个，完成率为"+QString::number(j)+"%,还可以表现得更好，下个月加油吧！";
        return s;
    }

    else if(j<50){
        QString s="本月共有"+QString::number(allnum)+"个ddl，完成了"+QString::number(finishednum)+"个，完成率为"+QString::number(j)+"%,这个月也太摆了，下个月可不能再这样下去了！";
        return s;
    }
}

bool YDBG::gettime(){
    QDate currentDate = QDate::currentDate();
    if (currentDate.day() == 1) {
        return 1;
    }
    else return 0;
}
QDate YDBG::rjdate(const QString &dateTimeString) {
    // 将200511051235这种格式的字符串转换为QDate
    int year = dateTimeString.mid(0, 4).toInt();
    int month = dateTimeString.mid(4, 2).toInt();
    int day = dateTimeString.mid(6, 2).toInt();
    return QDate(year, month, day);
}

int YDBG::get20(int k){
    int s=0;
    for(auto i=dairy.begin();i!=dairy.end();++i){
        if(i.value().state==0&&rjdate(i->current).month()==k){
            s++;
        }
    }
    return s;
}

int YDBG::get40(int k){
    int s=0;
    for(auto i=dairy.begin();i!=dairy.end();++i){
        if(i.value().state==1&&rjdate(i->current).month()==k){
            s++;
        }
    }
    return s;
}
int YDBG::get60(int k){
    int s=0;
    for(auto i=dairy.begin();i!=dairy.end();++i){
        if(i.value().state==2&&rjdate(i->current).month()==k){
            s++;
        }
    }
    return s;
}

int YDBG::get80(int k){
    int s=0;
    for(auto i=dairy.begin();i!=dairy.end();++i){
        if(i.value().state==3&&rjdate(i->current).month()==k){
            s++;
        }
    }
    return s;
}
int YDBG::get100(int k){
    int s=0;
    for(auto i=dairy.begin();i!=dairy.end();++i){
        if(i.value().state==4&&rjdate(i->current).month()==k){
            s++;
        }
    }
    return s;
}
DDL::DDL(QString s1,QString s2,QString s3,int a):ALL(s1,s2),ddl(s3),state(a){}
DDL::DDL(){}
DDL::DDL(QString s1,QString s2,QString s3,int a,QString s4,int a1,int a2,int a3):ALL(s1,s2,s4),ddl(s3),state(a){
    id_ddl++;
    id=id_ddl;
    remindtime=a1;
    hasremind=a2;
    hasfinished=a3;
}
void DDL::change(QString newddl,int newstate){
    ddl=newddl;
    state=newstate;
    time_t now=time(NULL);
    time_t ddl_time=times(ddl);
    int seconds=ddl_time-now;
    remindtime=((state*60*60*24)*0.5+seconds*0.2)/60;
}
bool DDL::operator<(DDL &a){
    if(hasfinished!=a.hasfinished){
        return hasfinished>a.hasfinished;
    }
    else if(state!=a.state)return state<a.state;
    else{
        return ddl>a.ddl;
    }
}//排序（按是否完成再按优先级再按时间）
void DDL::reminding(){

}//(提醒函数：在达到提醒时间时提醒，并且在仅剩1，2,3天时提醒)

void littleDDL::finishing(int i){
    finish_one=i;
    subtasks[i].hasfinished=true;
}//每次把完成的那个标号输进来
//ddl部分




Dairy::Dairy(){}
Dairy::Dairy(QString s1,QString s2,int n,QString s4):ALL(s1,s2),state(n),weather(s4){
    id_dairy++;
    _id=id_dairy;
}
Dairy::Dairy(QString s1,QString s2,int n,QString s3,QString s4):ALL(s1,s2,s3),state(n),weather(s4){
    id_dairy++;
    _id=id_dairy;
}
void Dairy::deleting(int _id){
    for(auto i = dairy.begin(); i != dairy.end(); i ++){
        if(i.value()._id == _id){
            dairy.erase(i);
            break;
        }
    }
    DairyToFile(dairy, "D:/dairy.txt");



}
bool Dairy::operator<(const Dairy &a){
    return current>a.current;
};
void Dairy::searchtitle(QString _title){
    for(auto i = dairy.begin(); i != dairy.end(); i ++){
        if(i->title.contains(_title)){
           // std::cout << i->title << endl;
            //暂定为输出标题
        }
    }
}
void Dairy::searchtime(QString _time){
    for(auto i = dairy.begin(); i != dairy.end(); i ++){
        if(i->current == _time){
           // std::cout << i->title << endl;
            //暂定为输出标题
        }
    }
}
//dairy部分
//下面是心情有关的文本
