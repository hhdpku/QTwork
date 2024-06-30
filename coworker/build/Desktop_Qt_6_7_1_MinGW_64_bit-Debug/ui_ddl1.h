/********************************************************************************
** Form generated from reading UI file 'ddl1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDL1_H
#define UI_DDL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDL1
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *DDL1)
    {
        if (DDL1->objectName().isEmpty())
            DDL1->setObjectName("DDL1");
        DDL1->resize(638, 333);
        pushButton = new QPushButton(DDL1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 140, 80, 24));
        pushButton_2 = new QPushButton(DDL1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 140, 80, 24));
        pushButton_3 = new QPushButton(DDL1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 140, 80, 24));

        retranslateUi(DDL1);

        QMetaObject::connectSlotsByName(DDL1);
    } // setupUi

    void retranslateUi(QWidget *DDL1)
    {
        DDL1->setWindowTitle(QCoreApplication::translate("DDL1", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("DDL1", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DDL1", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DDL1", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDL1: public Ui_DDL1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDL1_H
