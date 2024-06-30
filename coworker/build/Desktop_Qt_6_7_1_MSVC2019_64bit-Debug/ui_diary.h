/********************************************************************************
** Form generated from reading UI file 'diary.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIARY_H
#define UI_DIARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diary
{
public:

    void setupUi(QWidget *diary)
    {
        if (diary->objectName().isEmpty())
            diary->setObjectName("diary");
        diary->resize(400, 300);

        retranslateUi(diary);

        QMetaObject::connectSlotsByName(diary);
    } // setupUi

    void retranslateUi(QWidget *diary)
    {
        diary->setWindowTitle(QCoreApplication::translate("diary", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class diary: public Ui_diary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIARY_H
