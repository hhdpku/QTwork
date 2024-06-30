/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labeldiary;
    QScrollArea *ddlscroll;
    QWidget *scrollAreaWidgetContents_2;
    QFrame *line;
    QScrollArea *diaryscroll;
    QWidget *scrollAreaWidgetContents_3;
    QFrame *line_2;
    QLabel *labelddl;
    QPushButton *pushButton;
    QPushButton *addddl;
    QPushButton *adddiary;
    QPushButton *month;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(630, 602);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labeldiary = new QLabel(centralwidget);
        labeldiary->setObjectName("labeldiary");
        labeldiary->setEnabled(true);
        labeldiary->setGeometry(QRect(250, 0, 261, 41));
        ddlscroll = new QScrollArea(centralwidget);
        ddlscroll->setObjectName("ddlscroll");
        ddlscroll->setGeometry(QRect(0, 40, 241, 481));
        ddlscroll->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 239, 479));
        line = new QFrame(scrollAreaWidgetContents_2);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, -40, 20, 631));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        ddlscroll->setWidget(scrollAreaWidgetContents_2);
        diaryscroll = new QScrollArea(centralwidget);
        diaryscroll->setObjectName("diaryscroll");
        diaryscroll->setGeometry(QRect(260, 40, 311, 481));
        diaryscroll->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 309, 479));
        line_2 = new QFrame(scrollAreaWidgetContents_3);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(-10, -40, 20, 401));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        diaryscroll->setWidget(scrollAreaWidgetContents_3);
        labelddl = new QLabel(centralwidget);
        labelddl->setObjectName("labelddl");
        labelddl->setGeometry(QRect(0, 0, 241, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 10, 61, 31));
        addddl = new QPushButton(centralwidget);
        addddl->setObjectName("addddl");
        addddl->setGeometry(QRect(190, 520, 61, 41));
        adddiary = new QPushButton(centralwidget);
        adddiary->setObjectName("adddiary");
        adddiary->setGeometry(QRect(510, 520, 61, 41));
        month = new QPushButton(centralwidget);
        month->setObjectName("month");
        month->setGeometry(QRect(570, 40, 61, 481));
        QFont font;
        font.setPointSize(18);
        month->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 41, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/clock.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 0, 41, 41));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/diary1.jpg")));
        label_2->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 630, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labeldiary->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; font-style:italic;\">\346\227\245\350\256\260</span></p></body></html>", nullptr));
        labelddl->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; font-style:italic;\">ddl\347\256\241\347\220\206\345\231\250</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        addddl->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        adddiary->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        month->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
