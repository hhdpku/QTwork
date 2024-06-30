/********************************************************************************
** Form generated from reading UI file 'note.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE_H
#define UI_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_note
{
public:

    void setupUi(QWidget *note)
    {
        if (note->objectName().isEmpty())
            note->setObjectName("note");
        note->resize(400, 300);

        retranslateUi(note);

        QMetaObject::connectSlotsByName(note);
    } // setupUi

    void retranslateUi(QWidget *note)
    {
        note->setWindowTitle(QCoreApplication::translate("note", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class note: public Ui_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H
