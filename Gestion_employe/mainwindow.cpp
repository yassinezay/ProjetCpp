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
     if(e.recherche(e.getID()))
     {
     msgbox.setText("erreur");
    }else
     {
     bool test=e.ajouter();

         if(test){
             msgbox.setText("Ajouter avec succes");
         }
    }
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
/*
void MainWindow::on_pushButton_3_clicked()
{

}*/

void MainWindow::on_pushButton_9_clicked()
{
    ui->Ajouter->setCurrentIndex(2);

}

void MainWindow::on_pushButton_8_clicked()
{
    QMessageBox msgbox;
    int id=ui->ID_2->text().toInt();
     QString nom=ui->nom_2->text();
     QString prenom=ui->prenom_2->text();
     int cin=ui->cin_2->text().toInt();
     QString adresse=ui->adresse_2->text();
     QString designation=ui->desi_2->text();

     employe e(id,nom,prenom,cin,adresse,designation);
     e.setID(ui->ID_2->text().toInt());

     if(e.recherche(e.getID()))
     {
         bool test=e.modifier(id);
     if(test){
         msgbox.setText("modifier avec succes");
     }}else
     msgbox.setText("id introuvable!!");
         msgbox.exec();
}

void MainWindow::on_modif_8_clicked()
{
    ui->Ajouter->setCurrentIndex(0);

}
