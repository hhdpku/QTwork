/********************************************************************************
** Form generated from reading UI file 'notedial.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEDIAL_H
#define UI_NOTEDIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_notedial
{
public:
    QPushButton *editbutton_note;
    QPushButton *confirmbutton_note;

    void setupUi(QDialog *notedial)
    {
        if (notedial->objectName().isEmpty())
            notedial->setObjectName("notedial");
        notedial->resize(400, 300);
        editbutton_note = new QPushButton(notedial);
        editbutton_note->setObjectName("editbutton_note");
        editbutton_note->setGeometry(QRect(90, 220, 80, 24));
        confirmbutton_note = new QPushButton(notedial);
        confirmbutton_note->setObjectName("confirmbutton_note");
        confirmbutton_note->setGeometry(QRect(200, 220, 80, 24));

        retranslateUi(notedial);

        QMetaObject::connectSlotsByName(notedial);
    } // setupUi

    void retranslateUi(QDialog *notedial)
    {
        notedial->setWindowTitle(QCoreApplication::translate("notedial", "Dialog", nullptr));
        editbutton_note->setText(QCoreApplication::translate("notedial", "\347\274\226\350\276\221", nullptr));
        confirmbutton_note->setText(QCoreApplication::translate("notedial", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class notedial: public Ui_notedial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEDIAL_H
