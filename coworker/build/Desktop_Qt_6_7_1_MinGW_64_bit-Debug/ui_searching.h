/********************************************************************************
** Form generated from reading UI file 'searching.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHING_H
#define UI_SEARCHING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Searching
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Searching)
    {
        if (Searching->objectName().isEmpty())
            Searching->setObjectName("Searching");
        Searching->resize(360, 473);
        pushButton = new QPushButton(Searching);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 0, 41, 31));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(12, 12));
        pushButton_2 = new QPushButton(Searching);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 0, 41, 41));
        pushButton_2->setIconSize(QSize(16, 16));
        scrollArea = new QScrollArea(Searching);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 39, 341, 421));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 419));
        scrollArea->setWidget(scrollAreaWidgetContents);
        lineEdit = new QLineEdit(Searching);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 0, 261, 41));
        lineEdit->setFont(font);

        retranslateUi(Searching);

        QMetaObject::connectSlotsByName(Searching);
    } // setupUi

    void retranslateUi(QWidget *Searching)
    {
        Searching->setWindowTitle(QCoreApplication::translate("Searching", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Searching", "\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("Searching", "<html><head/><body><p><img src=\":/image/R1.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Searching", "\350\257\267\350\276\223\345\205\245\346\240\207\351\242\230\346\210\226\345\205\263\351\224\256\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Searching: public Ui_Searching {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHING_H
