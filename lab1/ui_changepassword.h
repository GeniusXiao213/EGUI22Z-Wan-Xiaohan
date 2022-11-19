/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changePassword
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *changePassword)
    {
        if (changePassword->objectName().isEmpty())
            changePassword->setObjectName("changePassword");
        changePassword->resize(313, 252);
        groupBox = new QGroupBox(changePassword);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 271, 181));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(102, 30, 111, 20));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(102, 60, 111, 20));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(102, 90, 111, 20));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 101, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 91, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 91, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 130, 80, 18));

        retranslateUi(changePassword);

        QMetaObject::connectSlotsByName(changePassword);
    } // setupUi

    void retranslateUi(QDialog *changePassword)
    {
        changePassword->setWindowTitle(QCoreApplication::translate("changePassword", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("changePassword", "change password", nullptr));
        label->setText(QCoreApplication::translate("changePassword", "old password", nullptr));
        label_2->setText(QCoreApplication::translate("changePassword", "new password", nullptr));
        label_3->setText(QCoreApplication::translate("changePassword", "confirm", nullptr));
        pushButton->setText(QCoreApplication::translate("changePassword", "change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changePassword: public Ui_changePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
