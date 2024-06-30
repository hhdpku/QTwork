/********************************************************************************
** Form generated from reading UI file 'ddldetailwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDLDETAILWINDOW_H
#define UI_DDLDETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DDLDetailWindow
{
public:
    QLabel *titleLabel;
    QLabel *deadlineLabel;
    QSpinBox *stateEdit;
    QPushButton *modifyButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *DDLDetailWindow)
    {
        if (DDLDetailWindow->objectName().isEmpty())
            DDLDetailWindow->setObjectName("DDLDetailWindow");
        DDLDetailWindow->resize(400, 487);
        titleLabel = new QLabel(DDLDetailWindow);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(20, 25, 351, 71));
        deadlineLabel = new QLabel(DDLDetailWindow);
        deadlineLabel->setObjectName("deadlineLabel");
        deadlineLabel->setGeometry(QRect(19, 141, 351, 71));
        stateEdit = new QSpinBox(DDLDetailWindow);
        stateEdit->setObjectName("stateEdit");
        stateEdit->setGeometry(QRect(20, 250, 351, 61));
        modifyButton = new QPushButton(DDLDetailWindow);
        modifyButton->setObjectName("modifyButton");
        modifyButton->setGeometry(QRect(20, 390, 161, 51));
        deleteButton = new QPushButton(DDLDetailWindow);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(200, 390, 161, 51));

        retranslateUi(DDLDetailWindow);

        QMetaObject::connectSlotsByName(DDLDetailWindow);
    } // setupUi

    void retranslateUi(QDialog *DDLDetailWindow)
    {
        DDLDetailWindow->setWindowTitle(QCoreApplication::translate("DDLDetailWindow", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("DDLDetailWindow", "TextLabel", nullptr));
        deadlineLabel->setText(QCoreApplication::translate("DDLDetailWindow", "TextLabel", nullptr));
        modifyButton->setText(QCoreApplication::translate("DDLDetailWindow", "\344\277\256\346\224\271", nullptr));
        deleteButton->setText(QCoreApplication::translate("DDLDetailWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDLDetailWindow: public Ui_DDLDetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDLDETAILWINDOW_H
