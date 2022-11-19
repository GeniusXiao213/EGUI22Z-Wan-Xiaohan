/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QAction *actionlog_out;
    QAction *actiondelete_account;
    QAction *actionsearch_for_books;
    QAction *actioncancel_reservation;
    QAction *actionchange_password;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");
        MainWindow2->resize(753, 729);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        MainWindow2->setFont(font);
        actionlog_out = new QAction(MainWindow2);
        actionlog_out->setObjectName("actionlog_out");
        actiondelete_account = new QAction(MainWindow2);
        actiondelete_account->setObjectName("actiondelete_account");
        actionsearch_for_books = new QAction(MainWindow2);
        actionsearch_for_books->setObjectName("actionsearch_for_books");
        actioncancel_reservation = new QAction(MainWindow2);
        actioncancel_reservation->setObjectName("actioncancel_reservation");
        actionchange_password = new QAction(MainWindow2);
        actionchange_password->setObjectName("actionchange_password");
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 0, 191, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font1.setPointSize(11);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 320, 151, 20));
        label_2->setFont(font1);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(620, 480, 121, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(430, 260, 101, 20));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(580, 260, 161, 20));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(650, 300, 91, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 260, 113, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 260, 91, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(570, 440, 91, 16));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(680, 440, 61, 20));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 20, 701, 221));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(40, 350, 521, 191));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 260, 119, 18));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(250, 280, 119, 18));
        MainWindow2->setCentralWidget(centralwidget);
        listWidget->raise();
        label->raise();
        label_2->raise();
        pushButton_2->raise();
        label_3->raise();
        lineEdit->raise();
        pushButton_3->raise();
        lineEdit_2->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_3->raise();
        listWidget_2->raise();
        pushButton->raise();
        pushButton_4->raise();
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 753, 16));
        menubar->setAutoFillBackground(false);
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionlog_out);
        menuMenu->addAction(actiondelete_account);
        menuMenu->addAction(actionchange_password);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        actionlog_out->setText(QCoreApplication::translate("MainWindow2", "log out", nullptr));
        actiondelete_account->setText(QCoreApplication::translate("MainWindow2", "delete account", nullptr));
        actionsearch_for_books->setText(QCoreApplication::translate("MainWindow2", "search for books", nullptr));
        actioncancel_reservation->setText(QCoreApplication::translate("MainWindow2", "cancel reservation", nullptr));
        actionchange_password->setText(QCoreApplication::translate("MainWindow2", "change password", nullptr));
        label->setText(QCoreApplication::translate("MainWindow2", "LIBRARY", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow2", "MY ACCOUNT", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow2", "Cancel reservation", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow2", "Enter book name", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow2", "Search", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow2", "Insert an ID", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow2", "Insert an ID", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow2", "Borrow", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow2", "Reserve", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow2", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
