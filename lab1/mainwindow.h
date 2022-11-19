#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "librarianui.h"
//#include "searchbookwindow.h"
#include <fstream>
#include <json.hpp>
#include "json.hpp"
#include <string>
#include <vector>

typedef struct {
    std::string user;
    std::string pwd;
} User;

void from_json(const nlohmann::json& j, User& p);
void to_json(nlohmann::json& j, const User& p);


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow2 *mainwindow2;
    LibrarianUI *librarianUI;

};
#endif // MAINWINDOW_H
