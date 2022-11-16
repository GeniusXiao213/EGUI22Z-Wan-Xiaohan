#ifndef LIBRARIANUI_H
#define LIBRARIANUI_H

#include <QMainWindow>

namespace Ui {
class LibrarianUI;
}

class LibrarianUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibrarianUI(QWidget *parent = nullptr);
    ~LibrarianUI();
    void showBooks();

private slots:
    void on_actionlog_out_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::LibrarianUI *ui;
};

#endif // LIBRARIANUI_H
