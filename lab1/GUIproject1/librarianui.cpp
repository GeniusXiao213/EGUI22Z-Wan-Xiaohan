#include "librarianui.h"
#include "ui_librarianui.h"
#include "mainwindow.h"
#include "book.h"
#include<QMessageBox>       //librarian interface

extern std::vector<Book> books;

LibrarianUI::LibrarianUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianUI)
{
    ui->setupUi(this);
    std::ifstream ifs( "books.json" );
    auto jf = nlohmann::json::parse( ifs );
    ifs.close();
    books = jf.get<std::vector<Book>>();
    showBooks();
}

LibrarianUI::~LibrarianUI()
{
    delete ui;
}

QString checkBookIfReserved(Book a)
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


void LibrarianUI::on_actionlog_out_triggered()  //log out
{
    hide();
    MainWindow *loginscreen= new MainWindow();
    loginscreen->show();
}

void LibrarianUI::showBooks()
{
    ui->listWidget->clear();
    QString intro="ID|--------------------TITLE-------------------|-----AUTHOR-----|-DATE-|------PUBLISHER------|--STATUS--|--USER--|";
    ui->listWidget->addItem(intro);
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        QString bookInformation = QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
                + QString::fromStdString( books[i].author ) + " | "
                + QString::number( books[i].date ) + " | "
                +QString::fromStdString( books[i].publisher ) + " | "+checkBookIfReserved(books[i])+ " | "+QString::fromStdString(books[i].user)+ " | "
                ;
        ui->listWidget->addItem( bookInformation );
    }
    return;
}


void LibrarianUI::on_pushButton_clicked()  //rent
{
    std::ifstream ifs( "books.json" );
    auto jf =  nlohmann::json::parse( ifs );
    ifs.close();
    int num=ui->lineEdit->text().toInt();
    std::string name=ui->lineEdit_2->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user=="" && books[i].reserved=="")
        {
            QMessageBox::information(this,"Book Borrow","Renting book succeed!");
            books[i].user=name;
            std::ofstream ofs( "books.json" );
            ofs << std::setw( 2 ) << nlohmann::json( books ) << std::endl;
            ofs.close();
            showBooks();
            return;
        }
    }
    QMessageBox::warning(this,"Book Borrow","Renting book failed!");
}


void LibrarianUI::on_pushButton_2_clicked()  //return book
{
    std::ifstream ifs( "books.json" );
    auto jf =  nlohmann::json::parse( ifs );
    ifs.close();
    int num=ui->lineEdit->text().toInt();
    std::string name=ui->lineEdit_2->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user==name)
        {
            QMessageBox::information(this,"Lease book","Leasing book succeed!");
            books[i].user="";
            books[i].leased="";
            std::ofstream ofs( "books.json" );
            ofs << std::setw( 2 ) << nlohmann::json( books ) << std::endl;
            ofs.close();
            showBooks();
            return;
        }
    }
    QMessageBox::warning(this,"Lease book","Leasing book failed!");
}

void LibrarianUI::on_pushButton_3_clicked()  //reserve book
{
    std::ifstream ifs( "books.json" );
    auto jf =  nlohmann::json::parse( ifs );
    ifs.close();
    int num=ui->lineEdit->text().toInt();
    std::string name=ui->lineEdit_2->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user=="" && books[i].reserved=="")
        {
            QMessageBox::information(this,"Reserve book","Reserving book succeed!");
            books[i].reserved=name;
            books[i].user=name;
            std::ofstream ofs( "books.json" );
            ofs << std::setw( 2 ) << nlohmann::json( books ) << std::endl;
            ofs.close();
            showBooks();
            return;
        }
    }
    QMessageBox::warning(this,"Reserve book","Reserving book failed!");
}

