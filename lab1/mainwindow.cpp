#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "main.cpp"
#include <iostream>
#include <string>
#include <vector>
//#include "mainwindow2.cpp"
//#include "booklist.h"
#include<QMessageBox>


void from_json(const nlohmann::json& j, User& p) {
    j.at("user").get_to(p.user);
    j.at("pwd").get_to(p.pwd);
}

void to_json(nlohmann::json& j, const User& p) {
    j = nlohmann::json{
      {"user", p.user}, {"pwd", p.pwd}
    };
}

std::map<std::string,std::string> userInfo;
std::vector<User> users;
std::string currentUserName;
std::string currentUserPwd;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::ifstream ifs("users.json");
    auto jf =  nlohmann::json::parse(ifs);
    ifs.close();
    users = jf.get<std::vector<User>>();

    for(unsigned long i=0; i<users.size(); i++ ){
           userInfo[users[i].user] = users[i].pwd;
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //SignIn button
{
    std::string username=ui->lineEdit_username->text().toStdString();
    std::string password=ui->lineEdit_password->text().toStdString();

    if(username!=""&&userInfo[username]==password)
    {

        currentUserN=username;
        currentUserName=username;
        currentUserPwd=password;
        if(currentUserN=="librarian")
        {
            QMessageBox::information(this,"Login","Welcome back,Librarian!");
            hide();
            librarianUI=new LibrarianUI(this);
            librarianUI->show();
        }
        else
        {
            QMessageBox::information(this,"Login","Welcome to WAN's Library!");
            hide();
            mainwindow2=new MainWindow2(this);
            mainwindow2->show();
        }
    }
    else
    {
        QMessageBox::warning(this,"Login","User or password is not correct!");
    }
}


bool checkIfExisted(std::string check)
{
    for(auto itr=userInfo.begin();itr!=userInfo.end();itr++)
    {
        if(check==itr->first)
        {
            return true;
        }
    }
    return false;
}



void MainWindow::on_pushButton_2_clicked() //SignUp button
{
    std::string username=ui->lineEdit_username->text().toStdString();
    std::string password=ui->lineEdit_password->text().toStdString();

    std::ifstream ifs("users.json");
    auto jf =  nlohmann::json::parse(ifs);
    ifs.close();
    auto users = jf.get<std::vector<User>>();

    for(unsigned long i=0; i<users.size(); i++ ){
           userInfo[users[i].user] = users[i].pwd;
       }

    if(username!=""&&userInfo[username]==password)
    {
        QMessageBox::warning(this,"SignUp","You are already a member of this library, please sign in with your existed account!");
    }
    else if(username==""||password=="")
    {
        QMessageBox::warning(this,"SignUp","Please input the correct form!");
    }
    else if(!checkIfExisted(username))
    {
        QMessageBox::warning(this,"SignUp","Please choose another name!");
    }
    else
    {
        QMessageBox::information(this,"SignUp","New Member! Welcome to WAN's Library!");
        users.push_back(User{username,password});
        MainWindow::currentUserN=username;
        MainWindow::currentUserP=password;
        currentUserName=currentUserN;
        currentUserPwd=currentUserP;

        userInfo[username]=password;
        std::ofstream ofs("output.json");
        ofs << std::setw(2) << nlohmann::json(users) << std::endl;
        //ofs.close();

        if(currentUserN=="librarian")
        {
            QMessageBox::information(this,"Login","Welcome back,Librarian!");
            hide();
            librarianUI=new LibrarianUI(this);
            librarianUI->show();
        }
        else
        {
            //QMessageBox::information(this,"Login","Welcome to WAN's Library!");
            hide();
            mainwindow2=new MainWindow2(this);
            mainwindow2->show();
        }
    }
}

