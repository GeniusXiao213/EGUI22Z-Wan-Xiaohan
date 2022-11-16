#include <QApplication>
#include <iostream>
#include "json.hpp"
#include"mainwindow.h"
//#include"mainwindow2.h"
#include <string>
#include <vector>
#include <fstream>
#include <json.hpp>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::ifstream ifs("users.json");
    auto jf =  nlohmann::json::parse(ifs);
    ifs.close();
    auto users = jf.get<std::vector<User>>();
    //std::cout << users[0].user << std::endl; // data read

    //users[0].pwd = "secret";                 // data modification
    //users.push_back(User{ "james", "567"});  // data insert
    //users.erase(users.begin()+1);            // data removal

    std::ofstream ofs("output.json");
    ofs << std::setw(2) << nlohmann::json(users) << std::endl;
    ofs.close();
    return a.exec();
}
