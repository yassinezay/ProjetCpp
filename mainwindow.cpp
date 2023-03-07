#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include "employe.h"
#include <QTextStream>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_modif_2_clicked()
{
    ui->Ajouter->setCurrentIndex(1);
}

void MainWindow::on_modif_4_clicked()
{
    ui->Ajouter->setCurrentIndex(0);

}

void MainWindow::on_modif_3_clicked()
{
    QMessageBox msgbox;
    int id=ui->ID->text().toInt();
     QString nom=ui->nom->text();
     QString prenom=ui->prenom->text();
     int cin=ui->cin->text().toInt();
     QString adresse=ui->adresse->text();
     QString designation=ui->desi->text();

     employe e(id,nom,prenom,cin,adresse,designation);
     e.setID(ui->ID->text().toInt());
     //if(e.recherche(e.getid()))
     //{
    // msgbox.setText("erreur");
     //}else
    // {
     bool test=e.ajouter();

         if(test){
             msgbox.setText("Ajouter avec succes");
         }
    //}
        msgbox.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    employe e;
       ui->tableemploye->setModel(e.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{

    QMessageBox msgbox;
employe e1;
e1.setID(ui->idsupprim->text().toInt());

bool test=e1.supprimer(e1.getID());

if(test){
    msgbox.setText("suppression avec succes");
}

    msgbox.exec();
}
