#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include "partenaire.h"
#include "stock.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stock e;
    partenaire p;
    ui->setupUi(this);
    ui->id->setValidator( new QIntValidator(100, 9999999, this));
    ui->idp->setValidator( new QIntValidator(100, 9999999, this));
    ui->tabstock->setModel(e.afficher());
    ui->tabpartenaire->setModel(p.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_ogrenci_5_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(2);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(1);
}

void MainWindow::on_btn_ogrenci_6_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(0);
}

void MainWindow::on_checkBox_3_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_checkBox_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);

}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(1);
}

void MainWindow::on_validers_clicked()
{
    QMessageBox msgbox;
    int id=ui->id->text().toInt();
    QString nom=ui->nomStock->text();
    QString prenom=ui->quantite->text();
    QString type=ui->typestock->text();
    stock e(id,nom,prenom,type);
   bool test=e.ajouter();
   if(test){
       msgbox.setText("ajouter avec succes");
   }else
   msgbox.setText("erreur");
       msgbox.exec();
}

void MainWindow::on_supprstock_clicked()
{
    QMessageBox msgbox;
stock e1;
e1.setid(ui->idsupp->text().toInt());
if(e1.recherche(e1.getid()))
{
bool test=e1.supprimer(e1.getid());

if(test){
    msgbox.setText("suppression avec succes");
}
}else
msgbox.setText("erreur");
    msgbox.exec();
}

void MainWindow::on_pushButton_valid_10_clicked()
{
    stock e;
    ui->tabstock->setModel(e.afficher());
}

void MainWindow::on_validpartenaire_clicked()
{
    QMessageBox msgbox;
    int id=ui->idp->text().toInt();
    QString nom=ui->nomp->text();
    int quantite=ui->quantitep->text().toInt();
    QString type=ui->typep->text();
    QString somme=ui->sommep->text();
    QString numtel=ui->nump->text();
    QString Date_convention = ui->date_partenaire->text();
    partenaire p(id,nom,numtel,type,quantite,somme,Date_convention);
    p.setid(ui->idp->text().toInt());
    if(p.recherche(p.getid()))
    {
    msgbox.setText("erreur");
    }else
    {bool test=p.ajouter();

        if(test){
            msgbox.setText("ajouter avec succes");
        }
   }
        msgbox.exec();
}

void MainWindow::on_pushButton_valid_16_clicked()
{
    partenaire p;
    ui->tabpartenaire->setModel(p.afficher());
}

void MainWindow::on_supp_partenaire_clicked()
{
    QMessageBox msgbox;
partenaire p;
p.setid(ui->idsupp_2->text().toInt());
if(p.recherche(p.getid()))
{
bool test=p.supprimer(p.getid());

if(test){
    msgbox.setText("suppression avec succes");
}
}else
msgbox.setText("erreur");
    msgbox.exec();
}

void MainWindow::on_pushButton_valid_18_clicked()
{
    partenaire p;
    QString type=ui->selectri->currentText();
    ui->tabpartenaire->setModel(p.tri(type));

}

void MainWindow::on_selectri_activated(const QString &arg1)
{
    partenaire p;



}

void MainWindow::on_modifierp_clicked()
{
    QMessageBox msgbox;
    int id=ui->idp->text().toInt();
    QString nom=ui->nomp->text();
    int quantite=ui->quantitep->text().toInt();
    QString type=ui->typep->text();
    QString somme=ui->sommep->text();
    QString numtel=ui->nump->text();
    QString Date_convention = ui->date_partenaire->text();
    partenaire p(id,nom,numtel,type,quantite,somme,Date_convention);
    p.setid(ui->idp->text().toInt());

   if(p.recherche(p.getid()))
   {
       bool test=p.modifier(id);
   if(test){
       msgbox.setText("modifier avec succes");
   }}else
   msgbox.setText("id introuvable!!");
       msgbox.exec();
}
