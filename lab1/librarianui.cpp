#include "librarianui.h"
#include "ui_librarianui.h"
#include "mainwindow.h"
#include "book.h"
#include<QMessageBox>

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

void LibrarianUI::on_actionlog_out_triggered()  //log out
{
    hide();
    MainWindow *loginscreen= new MainWindow();
    loginscreen->show();
}

void LibrarianUI::showBooks()
{

    ui->listWidget->clear();

   for( unsigned long i = 0; i < books.size(); i++ )
   {
       QString bookInformation = QString::number( books[i].id )+" | "+QString::fromStdString( books[i].title ) + " | "
               + QString::fromStdString( books[i].author ) + " | "
               + QString::fromStdString( books[i].title ) + " | "
               +QString::fromStdString( books[i].publisher ) + " | "+QString::fromStdString( books[i].user ) + " | "+
               QString::fromStdString( books[i].reserved) + " | "+QString::fromStdString( books[i].leased ) + " | "
               ;
       ui->listWidget->addItem( bookInformation );
   }
}

void LibrarianUI::on_pushButton_clicked()  //rent
{
    int num=ui->lineEdit->text().toInt();
    std::string name=ui->lineEdit_2->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user=="" && books[i].reserved=="")
        {
            QMessageBox::information(this,"Book Borrow","Renting book succeed!");
            books[i].user=name;
            return;
        }
    }
    QMessageBox::warning(this,"Book Borrow","Renting book failed!");
}


void LibrarianUI::on_pushButton_2_clicked()
{
    int num=ui->lineEdit->text().toInt();
    std::string name=ui->lineEdit_2->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user==name)
        {
            QMessageBox::information(this,"Lease book","Leasing book succeed!");
            books[i].user="";
            return;
        }
    }
    QMessageBox::warning(this,"Lease book","Leasing book failed!");
}


void LibrarianUI::on_pushButton_3_clicked()
{
    int num=ui->lineEdit->text().toInt();
    std::string name=ui->lineEdit_2->text().toStdString();
    for( unsigned long i = 0; i < books.size(); i++ )
    {
        if(num==books[i].id && books[i].user=="" && books[i].reserved=="")
        {
            QMessageBox::information(this,"Reserve book","Reserving book succeed!");
            books[i].reserved=name;
            return;
        }
    }
    QMessageBox::warning(this,"Reserve book","Reserving book failed!");
}

