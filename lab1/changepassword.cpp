#include "changepassword.h"
#include "mainwindow.h"
#include "ui_changepassword.h"
#include<QMessageBox>

extern std::string currentUserName;
extern std::string currentUserPwd;
extern std::map<std::string,std::string> userInfo2;
extern std::vector<User> users2;

changePassword::changePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePassword)
{
    ui->setupUi(this);
}

changePassword::~changePassword()
{
    delete ui;
}

void changePassword::on_pushButton_clicked()
{
    std::string oldPassword=ui->lineEdit->text().toStdString();
    std::string newPassword=ui->lineEdit_2->text().toStdString();
    std::string confirm=ui->lineEdit_3->text().toStdString();
    if(oldPassword==currentUserPwd&&newPassword==confirm)
    {
        QMessageBox::information(this,"password alteration","Changing password succeed!");
        currentUserPwd=newPassword;
        for(int i=0;i<users2.size();i++)
        {
            if(users2[i].user==currentUserName)
            {
                users2[i].pwd=newPassword;
            }
        }
        userInfo2[currentUserName]=newPassword;
        hide();
    }
    else
    {
        QMessageBox::warning(this,"password alteration","Something is wrong! Try again!");
    }
}

