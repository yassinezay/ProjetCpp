#include "supprimer.h"
#include "ui_supprimer.h"

supprimer::supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer)
{
    ui->setupUi(this);
}

supprimer::~supprimer()
{
    delete ui;
}
