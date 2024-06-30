/********************************************************************************
** Form generated from reading UI file 'ddl.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDL_H
#define UI_DDL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ddl
{
public:

    void setupUi(QWidget *ddl)
    {
        if (ddl->objectName().isEmpty())
            ddl->setObjectName("ddl");
        ddl->resize(638, 330);

        retranslateUi(ddl);

        QMetaObject::connectSlotsByName(ddl);
    } // setupUi

    void retranslateUi(QWidget *ddl)
    {
        ddl->setWindowTitle(QCoreApplication::translate("ddl", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ddl: public Ui_ddl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDL_H
