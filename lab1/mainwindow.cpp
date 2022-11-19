#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "main.cpp"
#include <iostream>
#include <string>
#include <vector>
//#include "mainwindow2.cpp"
//#include "booklist.h"
#include<QMessageBox>          //log in window


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
    //ui->set
    //ui->setBackground( Qt::white );
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

        currentUserName=username;
        currentUserPwd=password;
        if(currentUserName=="librarian")
        {
            QMessageBox::information(this,"Login","Welcome back,Librarian!");
            hide();
            librarianUI=new LibrarianUI(this);
            librarianUI->show();
            librarianUI->setFixedSize( 800, 600 );
        }
        else
        {
            QMessageBox::information(this,"Login","Welcome to WAN's Library!");
            hide();
            mainwindow2=new MainWindow2(this);
            mainwindow2->show();
            mainwindow2->setFixedSize( 800, 600 );
        }
    }
    else
    {
        QMessageBox::warning(this,"Login","User or password is not correct!");
    }
}


bool checkIfExisted(std::string check)
{
    for(auto itr=users.begin();itr!=users.end();itr++)
    {
        if(check==itr->user)
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

    if(password!=""&&username!=""&&userInfo[username]==password)
    {
        QMessageBox::warning(this,"SignUp","You are already a member of this library, please sign in with your existed account!");
    }
    else if(username==""||password=="")
    {
        QMessageBox::warning(this,"SignUp","Please input the correct form!");
    }
    else if(checkIfExisted(username))
    {
        QMessageBox::warning(this,"SignUp","Please choose another name!");
    }
    else
    {
        QMessageBox::information(this,"SignUp","New Member! Welcome to WAN's Library!Please sign in!");
        users.push_back(User{username,password});
        currentUserName=username;
        currentUserPwd=password;

        userInfo[username]=password;

        std::ofstream ofs( "users.json" );
        ofs << std::setw( 2 ) << nlohmann::json( users ) << std::endl;
        ofs.close();


    }
}

