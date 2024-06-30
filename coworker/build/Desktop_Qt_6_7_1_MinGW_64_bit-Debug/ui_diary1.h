/********************************************************************************
** Form generated from reading UI file 'diary1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIARY1_H
#define UI_DIARY1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diary1
{
public:

    void setupUi(QWidget *Diary1)
    {
        if (Diary1->objectName().isEmpty())
            Diary1->setObjectName("Diary1");
        Diary1->resize(400, 300);

        retranslateUi(Diary1);

        QMetaObject::connectSlotsByName(Diary1);
    } // setupUi

    void retranslateUi(QWidget *Diary1)
    {
        Diary1->setWindowTitle(QCoreApplication::translate("Diary1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Diary1: public Ui_Diary1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIARY1_H
