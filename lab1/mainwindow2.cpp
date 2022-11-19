#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow.h"
#include <iostream>
//#include "mainwindow.cpp"
#include <json.hpp>
#include <string>
#include <QDir>
#include <vector>
#include <string>
#include <fstream>
#include "book.h"
#include<QMessageBox>       //user interface

std::map<std::string,std::string> userInfo2;
extern std::vector<User> users;
std::vector<Book> books;

extern std::string currentUserName;
extern std::string currentUserPwd;

/*
 struct BookInfo{
     int id=0;
     std::string author = "";
     std::string title = "";
     std::string publisher = "";
     int date = 0;
     std::string user="";
     std::string reserved="";
     std::string leased="";
};
*/

using json = nlohmann::json;


void from_json2(const nlohmann::json& j, Book& p) {
    j.at( "id" ).get_to( p.id );
    j.at( "author" ).get_to( p.author );
    j.at( "title" ).get_to( p.title );
    j.at( "publisher" ).get_to( p.publisher );
    j.at( "date" ).get_to( p.date );
    j.at( "user" ).get_to( p.user );
    j.at( "leased" ).get_to( p.leased );
    j.at( "reserved" ).get_to( p.reserved );
}

void to_json2( nlohmann::json& j, const Book& p ) {
    j = nlohmann::json{ {"id", p.id},
                        {"author", p.author},
                        {"title", p.title},
                        {"publisher", p.publisher},
                        {"date", p.date},
                        {"user", p.user},
                        {"reserved", p.reserved},
                        {"leased", p.leased}
    };
}



MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    //getUser();
    ui->label_2->setText(QString::fromStdString(currentUserName)+"'s LIBRARY");
    std::ifstream ifs( "books.json" );
    auto jf = nlohmann::json::parse( ifs );
    ifs.close();
    books = jf.get<std::vector<Book>>();
    showBooks();

}

QString checkIfReserved(Book a)
{
    QString r="RESERVED";
    QString b="BROOWED";
    if(a.reserved!="")
    {
        return r;
    }
    else if(a.user!="")
    {
        return b;
    }
    else
    {
        return "AVAILABLE";
    }
}


void MainWindow2::showBooks()
{

    ui->listWidget->clear();
    QString intro="ID|--------------------TITLE-------------------|-----AUTHOR-----|-DATE-|------PUBLISHER------|--STATUS--|";
    ui->listWidget->addItem(intro);
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        QString bookInformation = QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
                + QString::fromStdString( books[i].author ) + " | "
                + QString::number( books[i].date ) + " | "
                +QString::fromStdString( books[i].publisher ) + " | "+checkIfReserved(books[i])
                ;
        ui->listWidget->addItem( bookInformation );
    }
    return;
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_actionlog_out_triggered() //log out button
{
    hide();
    MainWindow *loginscreen= new MainWindow();
    loginscreen->show();
}


void MainWindow2::on_actiondelete_account_triggered()  //delete account button
{
    int bookNum=0;
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(books[i].user==currentUserName||books[i].reserved==currentUserName)
        {
            bookNum++;
        }
    }  //check if the user has any borrowed or reserved book
    if(bookNum!=0)
    {
        QMessageBox::warning(this,"delete account","Deleting account failed!");
    }
    else
    {
        for(unsigned long int i=0;i<users.size();i++)
        {
            if (currentUserName == users[i].user && currentUserPwd == users[i].pwd)
            {
                users.erase(users.begin()+i);
                std::ofstream ofs("users.json");
                //std::ofstream ofs("output.json");
                ofs << std::setw(2) << nlohmann::json(users) << std::endl;
                QMessageBox::information(this,"delete account","Deleting account succeed!");
                hide();
                MainWindow *loginscreen= new MainWindow();
                loginscreen->show();
                return;
            }

        }
        QMessageBox::warning(this,"delete account","Deleting account failed!");
    }

}

void MainWindow2::on_actionchange_password_triggered() //change password button
{
    changePassword *changepassword=new changePassword();
    changepassword->show();
}

void MainWindow2::reloadBooks()
{
    ui->listWidget->clear();
    QString intro="ID|--------------------TITLE-------------------|-----AUTHOR-----|-DATE-|------PUBLISHER------|--STATUS--|";
    ui->listWidget->addItem(intro);
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        QString bookInformation = QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
                + QString::fromStdString( books[i].author ) + " | "
                + QString::number( books[i].date ) + " | "
                +QString::fromStdString( books[i].publisher ) + " | "+checkIfReserved(books[i])
                ;
        ui->listWidget->addItem( bookInformation );
    }
    return;
}

void MainWindow2::reloadUserBooks()
{
    ui->listWidget_2->clear();
    QString intro="ID|--------------------TITLE-------------------|-----AUTHOR-----|-DATE-|------PUBLISHER------|--STATUS--|";
    ui->listWidget_2->addItem(intro);
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(books[i].user==currentUserName||books[i].reserved==currentUserName)
        {
            QString bookInformation = QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
                    + QString::fromStdString( books[i].author ) + " | "
                    + QString::number( books[i].date ) + " | "
                    +QString::fromStdString( books[i].publisher ) + " | "+checkIfReserved(books[i])
                    ;
            ui->listWidget_2->addItem( bookInformation );
        }

    }
    return;
}

void MainWindow2::on_pushButton_clicked()    //borrow a book
{
    std::ifstream ifs( "books.json" );
    auto jf =  nlohmann::json::parse( ifs );
    ifs.close();
    books = jf.get<std::vector<Book>>();

    int num=ui->lineEdit_2->text().toInt();

    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user=="" && books[i].reserved=="")
        {
            QMessageBox::information(this,"Book Borrow","Borrowing book succeed!");
            books[i].user=currentUserName;
            std::ofstream ofs( "books.json" );
            ofs << std::setw( 2 ) << nlohmann::json( books ) << std::endl;
            ofs.close();

            QString bookInformation = QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
                    + QString::fromStdString( books[i].author ) + " | "
                    + QString::number( books[i].date ) + " | "
                    +QString::fromStdString( books[i].publisher ) + " | "+checkIfReserved(books[i])
                    ;

            ui->listWidget_2->addItem( bookInformation );
            reloadBooks();
            return;
        }
    }
    QMessageBox::warning(this,"Book Borrow","Borrowing book failed!");
}

void MainWindow2::on_pushButton_3_clicked()   //search for book
{


    std::string bookSearchName=ui->lineEdit->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(books[i].title.find(bookSearchName)!= std::string::npos)
        {
            QMessageBox::information(this,"Book found!","Book info: "+QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
                                     + QString::fromStdString( books[i].author ) + " | "
                                     + QString::number( books[i].date ) + " | "
                                     +QString::fromStdString( books[i].publisher ) + " | "+checkIfReserved(books[i])
                                     );
            return;
        }
    }
    QMessageBox::warning(this,"Book not found!","No such book in library!");
    return;
}


void MainWindow2::on_pushButton_4_clicked()  // reserve a book
{
    std::ifstream ifs( "books.json" );
    auto jf =  nlohmann::json::parse( ifs );
    ifs.close();
    books = jf.get<std::vector<Book>>();

    int num=ui->lineEdit_2->text().toInt();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user=="" && books[i].reserved=="")
        {
            QMessageBox::information(this,"Book Reservation","Reserving book succeed!");
            books[i].user=currentUserName;
            books[i].reserved=currentUserName;

            std::ofstream ofs( "books.json" );
            ofs << std::setw( 2 ) << nlohmann::json( books ) << std::endl;
            ofs.close();

            //reload books in both library and user's account
            reloadBooks();
            reloadUserBooks();
            return;
        }
    }
    QMessageBox::warning(this,"Book Reservation","Reserving book failed!");
}


void MainWindow2::on_pushButton_2_clicked()  // cancel reservation
{
    std::ifstream ifs( "books.json" );
    auto jf =  nlohmann::json::parse( ifs );
    ifs.close();
    int num=ui->lineEdit_3->text().toInt();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].reserved==currentUserName)
        {
            QMessageBox::information(this,"Cancel Reservation","Cancelling Reservation succeed!");
            books[i].user="";
            books[i].reserved="";
            std::ofstream ofs( "books.json" );
            ofs << std::setw( 2 ) << nlohmann::json( books ) << std::endl;
            ofs.close();
            reloadUserBooks();

            return;
        }
    }
    QMessageBox::warning(this,"Cancel Reservation","Cancelling Reservation failed!");

}

