#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include "partenaire.h"
#include "stock.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinter>
#include "notification.h"

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
    ui->listView->setModel(p.afficher_historique0());
    ui->TABRECHS->setModel(e.afficher());



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
//gestion stock

void MainWindow::on_validers_clicked()
{
    QMessageBox msgbox;

    int id=ui->id->text().toInt();
    QString nom=ui->nomStock->text();
    QString prenom=ui->quantite->text();
    QString type=ui->typestock->text();
    QDateTime date=ui->dates->dateTime();
    QRegExp regex("^[A-Za-z]+$");
    QRegExp regex1("^[0-9]+$");


    stock p(id,nom,prenom,type,date);
    p.setid(ui->id->text().toInt());
    if (id < 0 || !id)
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme id"),
                    QObject::tr("verifier id\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if (!regex.exactMatch(nom))
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter un nom \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ( !regex.exactMatch(type)  )
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter un type de stock !! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ( !regex1.exactMatch(prenom) )
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter le quantite  !! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
  else
    {
   stock P(id,nom,prenom,type,date);
    p.setid(ui->id->text().toInt());
    if(p.recherche(p.getid()))
    {
    msgbox.setText("stock existe deja");
    }else
    {bool test=p.ajouter();

        if(test){
            msgbox.setText("ajouter avec succes");
        }
   }
        msgbox.exec();
    }
}

void MainWindow::on_supprstock_clicked()
{
    QMessageBox msgbox;
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur est ce que vous etes sur de supprimer cet stock ?", QMessageBox ::Yes | QMessageBox::No);

stock p;
p.setid(ui->idsupp->text().toInt());

    if (reponse == QMessageBox::Yes)
    {
        if(p.recherche(p.getid()))
        {
        bool test=p.supprimer(p.getid());
        if(test){
            msgbox.setText("suppression avec succes");
        }
        }else
        msgbox.setText("stock introuvable !!");
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::information(this, "Careness", "Annulation!");
    }


    msgbox.exec();
}

void MainWindow::on_pushButton_valid_10_clicked()
{
    stock e;
    ui->tabstock->setModel(e.afficher());
}

void MainWindow::on_modifierStock_clicked()
{
    QMessageBox msgbox;
    int id=ui->id->text().toInt();
    QString nom=ui->nomStock->text();
    QString prenom=ui->quantite->text();
    QString type=ui->typestock->text();
    QDateTime date=ui->dates->dateTime();
 stock e(id,nom,prenom,type,date);
    e.setid(ui->id->text().toInt());

   if(e.recherche(e.getid()))
   {
       bool test=e.modifier(id);
   if(test){
       msgbox.setText("modifier avec succes");
   }}else
   msgbox.setText("id introuvable!!");
       msgbox.exec();
}
void MainWindow::on_treeStock_clicked()
{
    stock s;
    QString type=ui->nomdetrii->currentText();
    ui->tabstock->setModel(s.tri(type));
}


void MainWindow::on_pushButton_valid_11_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(4);
}

void MainWindow::on_BRS_clicked()
{
    stock s;
    QString nom=ui->RECHERCHES->text();
     ui->TABRECHS->setModel(s.afficherRS(nom));
}

void MainWindow::on_BRS_2_clicked()
{
    stock s;
    QString nom=ui->RECHERCHES_2->text();
     ui->tabstock->setModel(s.afficherRS(nom));
}
//end gestion stock

//gestion partenaire

void MainWindow::on_validpartenaire_clicked()
{

    QMessageBox msgbox;
    notification n;
    int id=ui->idp->text().toInt();
    QString nom=ui->nomp->text();
    int quantite=ui->quantitep->text().toInt();
    QString type=ui->typep->text();
    QString somme=ui->sommep->text();
    QString numtel=ui->nump->text();
    QRegularExpression regex("^\\+216[0-9]{8}$");
    QRegExp regex1("^[A-Za-z]+$");
    QDateTime Date_convention = ui->date_partenaire->dateTime();
    if (id < 0 || !id)
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme id"),
                    QObject::tr("verifier id\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if (!regex1.exactMatch(nom))
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter un nom \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ( type.isEmpty() && somme.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter un type de don !! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ( !regex.match(numtel).hasMatch() )
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter le numero de telephone correct avec +216 !! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
  else
    {
    partenaire p(id,nom,numtel,type,quantite,somme,Date_convention);
    p.setid(ui->idp->text().toInt());


    if(p.recherche(p.getid()))
    {
    msgbox.setText("partenaire existe deja");
    }else
    {bool test=p.ajouter();

        if(test){

            msgbox.setText("ajouter avec succes");
            p.ajouter_historique("ajout",nom,id);
            ui->listView->setModel(p.afficher_historique0());
            n.notification_ajout();


        }
   }
        msgbox.exec();
    }
}

void MainWindow::on_pushButton_valid_16_clicked()
{
    partenaire p;
    ui->tabpartenaire->setModel(p.afficher());
}

void MainWindow::on_supp_partenaire_clicked()
{
    QMessageBox msgbox;
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur est ce que vous etes sur de supprimer cet partenaire ?", QMessageBox ::Yes | QMessageBox::No);

partenaire p;
p.setid(ui->idsupp_2->text().toInt());

    if (reponse == QMessageBox::Yes)
    {
        if(p.recherche(p.getid()))
        {
        bool test=p.supprimer(p.getid());
        if(test){
            msgbox.setText("suppression avec succes");
            p.ajouter_historique("suppression",ui->nomp->text(),ui->idp->text().toInt());
            ui->listView->setModel(p.afficher_historique0());


        }
        }else
        msgbox.setText("Partenaire introuvable !!");
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::information(this, "Careness", "Annulation!");
    }


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
    QDateTime Date_convention = ui->date_partenaire->dateTime();
    partenaire p(id,nom,numtel,type,quantite,somme,Date_convention);
    p.setid(ui->idp->text().toInt());

   if(p.recherche(p.getid()))
   {
       bool test=p.modifier(id);
   if(test){
       msgbox.setText("modifier avec succes");
       p.ajouter_historique("modification",nom,id);
       ui->listView->setModel(p.afficher_historique0());

   }}else
   msgbox.setText("id introuvable!!");
       msgbox.exec();
}



void MainWindow::on_btn_quitter_clicked()
{
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur est ce que tu veux quitter?", QMessageBox ::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::critical(this, "Careness", "A la prochaine !");
            close();
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::information(this, "Careness", "bienvenue!");
        }
}

void MainWindow::on_btn_gpartenaire_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(3);
}

void MainWindow::on_btn_phistorique_clicked()
{

    ui->stackedWidgetbar->setCurrentIndex(5);

}

void MainWindow::on_btn_retourp_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(3);


}

void MainWindow::on_pushButton_valid_14_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_pushButton_valid_15_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);

}

void MainWindow::on_BRp_clicked()
{
    partenaire p;
    QString nom=ui->RECHERCHESp->text();
     ui->tabpartenaire->setModel(p.afficherRSp(nom));
}


void MainWindow::on_pushButton_6_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tabpartenaire->model()->rowCount();
    const int columnCount = ui->tabpartenaire->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=lightblue link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste Des Stock </H1></br></br></tr></tr><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tabpartenaire->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tabpartenaire->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tabpartenaire->isColumnHidden(column))
            {
                QString data = ui->tabpartenaire->model()->data(ui->tabpartenaire->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
            "</body>\n"
            "<footer>"
            "<div align=right>"
              "Careness"
            "</div>"
            "<div align=left>"
              "Sender Name,signature<br>"
              "Ariana essoughra<br>"
              "Tunis"
            "</div>"
          "</footer>"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void MainWindow::on_pdfS_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tabstock->model()->rowCount();
    const int columnCount = ui->tabstock->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=lightblue link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste De stock </H1></br></br></tr></tr><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tabstock->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tabstock->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tabstock->isColumnHidden(column))
            {
                QString data = ui->tabstock->model()->data(ui->tabstock->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
            "</body>\n"
            "<footer>"
            "<div align=right>"
              "Careness"
            "</div>"
            "<div align=left>"
              "Sender Name,signature<br>"
              "Ariana essoughra<br>"
              "Tunis"
            "</div>"
          "</footer>"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void MainWindow::on_exitb_clicked()
{
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur est ce que tu veux quitter?", QMessageBox ::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::critical(this, "Careness", "A la prochaine !");
            close();
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::information(this, "Careness", "bienvenue!");
        }
}

void MainWindow::on_aff_clicked()
{
    partenaire p;
    QString type=ui->typehistorique->currentText();
    ui->listView->setModel(p.afficher_historique(type));
}

void MainWindow::on_tabpartenaire_activated(const QModelIndex &index)
{

        QString val=ui->tabpartenaire->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("SELECT *from partenaire where id='"+val+"' ");
        if (qry.exec())
        {
    while(qry.next())
        {
           ui->idp->setText(qry.value(0).toString());
          ui->nomp->setText(qry.value(1).toString());
            ui->nump->setText(qry.value(2).toString());
             ui->typep->setText(qry.value(3).toString());
             ui->quantitep->setValue(qry.value(4).toInt());
             ui->sommep->setText(qry.value(5).toString());
             ui->date_partenaire->setDate(qry.value(6).toDate());
             ui->idsupp_2->setText(qry.value(0).toString());

        }
        }else
             QMessageBox::question(this, "Interrogatoire", "Erreur", QMessageBox ::Yes );


}

void MainWindow::on_RECHERCHESp_textChanged(const QString &arg1)
{
    partenaire p;
       ui->tabpartenaire->setModel(p.recherchep2(arg1));
}

void MainWindow::on_listView_activated(const QModelIndex &index)
{

    QString val=ui->listView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT *from history where id='"+val+"' ");
    if (qry.exec())
    {
while(qry.next())
    {

      ui->nomsupp->setText(qry.value(2).toString());


    }
    }else
        QMessageBox::question(this, "Interrogatoire", "Erreur", QMessageBox ::Yes );


}

void MainWindow::on_supphistorique_clicked()
{
    QSqlQuery query;

         query.prepare("DELETE from history");

    query.exec();
}

void MainWindow::on_supphistorique_2_clicked()
{
    QMessageBox msgbox;
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur est ce que vous etes sur de supprimer cet partenaire ?", QMessageBox ::Yes | QMessageBox::No);

partenaire p;
p.setid(ui->nomsupp->text().toInt());

    if (reponse == QMessageBox::Yes)
    {
        bool test=p.supprimerh(p.getid());
        if(test){
            msgbox.setText("suppression avec succes");


        }

    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::information(this, "Careness", "Annulation!");
    }


    msgbox.exec();
}

void MainWindow::on_pdfhistorique_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->listView->model()->rowCount();
    const int columnCount = ui->listView->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=lightblue link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Historique </H1></br></br></tr></tr><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->listView->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->listView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->listView->isColumnHidden(column))
            {
                QString data = ui->listView->model()->data(ui->listView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
            "</body>\n"
            "<footer>"
            "<div align=right>"
              "Careness"
            "</div>"
            "<div align=left>"
              "Sender Name,signature<br>"
              "Ariana essoughra<br>"
              "Tunis"
            "</div>"
          "</footer>"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void MainWindow::on_RECHERCHES_2_textChanged(const QString &arg1)
{
   stock s;
       ui->tabstock->setModel(s.recherches2(arg1));
}

void MainWindow::on_tabstock_activated(const QModelIndex &index)
{
    QString val=ui->tabstock->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT *from stock where id='"+val+"' ");
    if (qry.exec())
    {
while(qry.next())
    {
       ui->id->setText(qry.value(0).toString());
      ui->nomStock->setText(qry.value(1).toString());
        ui->typestock->setText(qry.value(2).toString());
         ui->quantite->setText(qry.value(3).toString());
         ui->dates->setDate(qry.value(4).toDate());
         ui->idsupp->setText(qry.value(0).toString());

    }
    }else
         QMessageBox::question(this, "Interrogatoire", "Erreur", QMessageBox ::Yes );
}
void MainWindow::on_pushButton_valid_13_clicked(){


}

void MainWindow::on_btn_retourp_2_clicked()
{
    ui->stackedWidgetbar->setCurrentIndex(0);
}

void MainWindow::on_RECHERCHES_textChanged(const QString &arg1)
{
    stock s;
        ui->TABRECHS->setModel(s.recherches2(arg1));
}
