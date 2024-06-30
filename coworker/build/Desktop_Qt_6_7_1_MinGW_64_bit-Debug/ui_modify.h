/********************************************************************************
** Form generated from reading UI file 'modify.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_H
#define UI_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Modify
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *Modify)
    {
        if (Modify->objectName().isEmpty())
            Modify->setObjectName("Modify");
        Modify->resize(400, 372);
        buttonBox = new QDialogButtonBox(Modify);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Modify);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 10, 241, 41));
        QFont font;
        font.setPointSize(18);
        lineEdit->setFont(font);
        label = new QLabel(Modify);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 60, 101, 41));
        label_2 = new QLabel(Modify);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 10, 101, 41));
        textEdit = new QTextEdit(Modify);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(110, 70, 271, 261));

        retranslateUi(Modify);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Modify, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Modify, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Modify);
    } // setupUi

    void retranslateUi(QDialog *Modify)
    {
        Modify->setWindowTitle(QCoreApplication::translate("Modify", "Dialog", nullptr));
        lineEdit->setText(QString());
        label->setText(QCoreApplication::translate("Modify", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\344\277\256\346\224\271\346\226\207\346\234\254</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Modify", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\344\277\256\346\224\271\346\240\207\351\242\230</span></p></body></html>", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Modify", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modify: public Ui_Modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_H
