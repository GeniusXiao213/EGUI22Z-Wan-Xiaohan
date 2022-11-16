#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
//#include "mainwindow.h"
#include "changepassword.h"


namespace Ui {
class MainWindow2;
}


class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    void getUser();
    void showBooks();
    ~MainWindow2();

private slots:
    void on_actionlog_out_triggered();

    void on_actiondelete_account_triggered();
    void on_actionchange_password_triggered();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow2 *ui;
    changePassword *changepassword;
};

#endif // MAINWINDOW2_H
