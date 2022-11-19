/********************************************************************************
** Form generated from reading UI file 'librarianui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARIANUI_H
#define UI_LIBRARIANUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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

class Ui_LibrarianUI
{
public:
    QAction *actionsearch_book;
    QAction *actionlog_out;
    QAction *actionchange_status;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibrarianUI)
    {
        if (LibrarianUI->objectName().isEmpty())
            LibrarianUI->setObjectName("LibrarianUI");
        LibrarianUI->resize(1180, 689);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        LibrarianUI->setFont(font);
        actionsearch_book = new QAction(LibrarianUI);
        actionsearch_book->setObjectName("actionsearch_book");
        actionlog_out = new QAction(LibrarianUI);
        actionlog_out->setObjectName("actionlog_out");
        actionchange_status = new QAction(LibrarianUI);
        actionchange_status->setObjectName("actionchange_status");
        centralwidget = new QWidget(LibrarianUI);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 31, 751, 391));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 10, 81, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font1.setPointSize(11);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 430, 81, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 430, 51, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 430, 61, 16));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(440, 430, 113, 20));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(240, 460, 250, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        LibrarianUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibrarianUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1180, 16));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        LibrarianUI->setMenuBar(menubar);
        statusbar = new QStatusBar(LibrarianUI);
        statusbar->setObjectName("statusbar");
        LibrarianUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionlog_out);

        retranslateUi(LibrarianUI);

        QMetaObject::connectSlotsByName(LibrarianUI);
    } // setupUi

    void retranslateUi(QMainWindow *LibrarianUI)
    {
        LibrarianUI->setWindowTitle(QCoreApplication::translate("LibrarianUI", "MainWindow", nullptr));
        actionsearch_book->setText(QCoreApplication::translate("LibrarianUI", "search book", nullptr));
        actionlog_out->setText(QCoreApplication::translate("LibrarianUI", "log out", nullptr));
        actionchange_status->setText(QCoreApplication::translate("LibrarianUI", "change status", nullptr));
        label->setText(QCoreApplication::translate("LibrarianUI", "LIBRARY", nullptr));
        label_2->setText(QCoreApplication::translate("LibrarianUI", "book ID", nullptr));
        label_3->setText(QCoreApplication::translate("LibrarianUI", "user name", nullptr));
        pushButton->setText(QCoreApplication::translate("LibrarianUI", "rent", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LibrarianUI", "lease", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LibrarianUI", "reserve", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("LibrarianUI", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarianUI: public Ui_LibrarianUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARIANUI_H
