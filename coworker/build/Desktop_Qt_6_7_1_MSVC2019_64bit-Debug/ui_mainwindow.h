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
    QFrame *line;
    QFrame *line_2;
    QLabel *labeldiary;
    QScrollArea *ddlScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *diaryscroll;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *labelddl;
    QScrollArea *notescroll;
    QWidget *scrollAreaWidgetContents;
    QLabel *labelnote;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *addDDLButton;
    QPushButton *pushButton_2;
    QPushButton *adddiary;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(213, 0, 20, 591));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(460, 0, 20, 361));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        labeldiary = new QLabel(centralwidget);
        labeldiary->setObjectName("labeldiary");
        labeldiary->setEnabled(true);
        labeldiary->setGeometry(QRect(480, 10, 241, 31));
        ddlScrollArea = new QScrollArea(centralwidget);
        ddlScrollArea->setObjectName("ddlScrollArea");
        ddlScrollArea->setGeometry(QRect(220, 40, 251, 481));
        ddlScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 249, 479));
        ddlScrollArea->setWidget(scrollAreaWidgetContents_2);
        diaryscroll = new QScrollArea(centralwidget);
        diaryscroll->setObjectName("diaryscroll");
        diaryscroll->setGeometry(QRect(470, 40, 321, 481));
        diaryscroll->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 319, 479));
        diaryscroll->setWidget(scrollAreaWidgetContents_3);
        labelddl = new QLabel(centralwidget);
        labelddl->setObjectName("labelddl");
        labelddl->setGeometry(QRect(230, 10, 241, 31));
        notescroll = new QScrollArea(centralwidget);
        notescroll->setObjectName("notescroll");
        notescroll->setGeometry(QRect(0, 40, 221, 481));
        notescroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 479));
        notescroll->setWidget(scrollAreaWidgetContents);
        labelnote = new QLabel(centralwidget);
        labelnote->setObjectName("labelnote");
        labelnote->setGeometry(QRect(0, 10, 211, 31));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(470, 520, 261, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(730, 10, 61, 31));
        addDDLButton = new QPushButton(centralwidget);
        addDDLButton->setObjectName("addDDLButton");
        addDDLButton->setGeometry(QRect(410, 520, 61, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 520, 61, 41));
        adddiary = new QPushButton(centralwidget);
        adddiary->setObjectName("adddiary");
        adddiary->setGeometry(QRect(730, 520, 61, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
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
        labelnote->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; font-style:italic;\">\345\244\207\345\277\230\345\275\225</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        addDDLButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        adddiary->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
