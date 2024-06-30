/********************************************************************************
** Form generated from reading UI file 'yuedubaogao.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YUEDUBAOGAO_H
#define UI_YUEDUBAOGAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yuedubaogao
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *yuedubaogao)
    {
        if (yuedubaogao->objectName().isEmpty())
            yuedubaogao->setObjectName("yuedubaogao");
        yuedubaogao->resize(800, 600);
        centralwidget = new QWidget(yuedubaogao);
        centralwidget->setObjectName("centralwidget");
        yuedubaogao->setCentralWidget(centralwidget);
        menubar = new QMenuBar(yuedubaogao);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        yuedubaogao->setMenuBar(menubar);
        statusbar = new QStatusBar(yuedubaogao);
        statusbar->setObjectName("statusbar");
        yuedubaogao->setStatusBar(statusbar);

        retranslateUi(yuedubaogao);

        QMetaObject::connectSlotsByName(yuedubaogao);
    } // setupUi

    void retranslateUi(QMainWindow *yuedubaogao)
    {
        yuedubaogao->setWindowTitle(QCoreApplication::translate("yuedubaogao", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yuedubaogao: public Ui_yuedubaogao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YUEDUBAOGAO_H
