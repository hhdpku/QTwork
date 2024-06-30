/********************************************************************************
** Form generated from reading UI file 'note1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE1_H
#define UI_NOTE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Note1
{
public:

    void setupUi(QWidget *Note1)
    {
        if (Note1->objectName().isEmpty())
            Note1->setObjectName("Note1");
        Note1->resize(400, 300);

        retranslateUi(Note1);

        QMetaObject::connectSlotsByName(Note1);
    } // setupUi

    void retranslateUi(QWidget *Note1)
    {
        Note1->setWindowTitle(QCoreApplication::translate("Note1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Note1: public Ui_Note1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE1_H
