#include "login.h"
#include "ui_login.h"
#include <QStackedWidget>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
