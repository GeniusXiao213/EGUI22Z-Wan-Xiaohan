#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class changePassword;
}

class changePassword : public QDialog
{
    Q_OBJECT

public:
    explicit changePassword(QWidget *parent = nullptr);
    ~changePassword();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changePassword *ui;
};

#endif // CHANGEPASSWORD_H
