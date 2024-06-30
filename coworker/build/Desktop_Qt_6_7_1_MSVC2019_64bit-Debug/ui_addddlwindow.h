/********************************************************************************
** Form generated from reading UI file 'addddlwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDDLWINDOW_H
#define UI_ADDDDLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddDDLWindow
{
public:
    QLineEdit *titleEdit;
    QLineEdit *deadlineEdit;
    QSpinBox *stateEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *AddDDLWindow)
    {
        if (AddDDLWindow->objectName().isEmpty())
            AddDDLWindow->setObjectName("AddDDLWindow");
        AddDDLWindow->resize(399, 438);
        titleEdit = new QLineEdit(AddDDLWindow);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(80, 20, 291, 71));
        deadlineEdit = new QLineEdit(AddDDLWindow);
        deadlineEdit->setObjectName("deadlineEdit");
        deadlineEdit->setGeometry(QRect(80, 120, 291, 81));
        stateEdit = new QSpinBox(AddDDLWindow);
        stateEdit->setObjectName("stateEdit");
        stateEdit->setGeometry(QRect(80, 230, 291, 71));
        okButton = new QPushButton(AddDDLWindow);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(20, 370, 161, 31));
        cancelButton = new QPushButton(AddDDLWindow);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(210, 370, 161, 31));
        textEdit = new QTextEdit(AddDDLWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 20, 61, 71));
        textEdit_2 = new QTextEdit(AddDDLWindow);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(10, 120, 61, 81));
        textEdit_3 = new QTextEdit(AddDDLWindow);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(10, 230, 61, 71));

        retranslateUi(AddDDLWindow);

        QMetaObject::connectSlotsByName(AddDDLWindow);
    } // setupUi

    void retranslateUi(QDialog *AddDDLWindow)
    {
        AddDDLWindow->setWindowTitle(QCoreApplication::translate("AddDDLWindow", "Dialog", nullptr));
        okButton->setText(QCoreApplication::translate("AddDDLWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddDDLWindow", "\345\217\226\346\266\210", nullptr));
        textEdit->setHtml(QCoreApplication::translate("AddDDLWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700;\">\345\206\205\345\256\271</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("AddDDLWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:700;\">\346\210\252\346\255\242\346\227\266\351\227\264</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margi"
                        "n-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:700;\">\357\274\210XXXX-XX-XX)</span></p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("AddDDLWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">\351\207\215\350\246\201\347\250\213\345\272\246</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDDLWindow: public Ui_AddDDLWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDDLWINDOW_H
