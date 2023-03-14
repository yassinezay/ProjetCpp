#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include "event.h"
#include "stock.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Event E;
    ui->setupUi(this);
    ui->id->setValidator( new QIntValidator(100, 9999999, this));
     ui->idE->setValidator( new QIntValidator(100, 9999999, this));
    ui->tabevent->setModel(E.afficher());

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


 //gestion event

void MainWindow::on_validevent_clicked()
{
    QMessageBox msgbox;
    int id=ui->idE->text().toInt();
    QString nom=ui->nomE->text();
    QString type=ui->typeE->text();
    int nbrinvit=ui->nbrinvitE->text().toInt();
    QString endroit=ui->endroitE->text();
    QDate Date_event = ui->date_Event->date();
    if (id < 0 || !id)
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme id"),
                    QObject::tr("verifier id\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if (nom.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter un nom \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ( type.isEmpty() && endroit.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter un type  !! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ( endroit.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("probleme nom"),
                    QObject::tr("Il faut ajouter l'endroit !! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
  else
    {
     Event E(id,nom,type,nbrinvit,endroit,Date_event);
    E.setid(ui->idE->text().toInt());
    if(E.recherche(E.getid()))
    {
    msgbox.setText("event existe deja");
    }else
    {bool test=E.ajouter();

        if(test){
            msgbox.setText("ajouter avec succes");
        }
   }
        msgbox.exec();
    }
}


void MainWindow::on_pushButton_valid_16_clicked()
{
    Event E;
    ui->tabevent->setModel(E.afficher());
}

void MainWindow::on_supp_event_clicked()
{
    QMessageBox msgbox;
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur est ce que vous etes sur de supprimer cet event ?", QMessageBox ::Yes | QMessageBox::No);

Event E;
E.setid(ui->idsupp_E->text().toInt());

    if (reponse == QMessageBox::Yes)
    {
        if(E.recherche(E.getid()))
        {
        bool test=E.supprimer(E.getid());
        if(test){
            msgbox.setText("suppression avec succes");
        }
        }else
        msgbox.setText("event introuvable !!");
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::information(this, "Careness", "Annulation!");
    }


    msgbox.exec();
}

void MainWindow::on_pushButton_valid_18_clicked()
{
    Event E;
    QString type=ui->selectri->currentText();
    ui->tabevent->setModel(E.tri(type));

}

void MainWindow::on_selectri_activated(const QString &arg1)
{
    Event E;
}

void MainWindow::on_modifierE_clicked()
{
    QMessageBox msgbox;
    int id=ui->idE->text().toInt();
    QString nom=ui->nomE->text();
    QString type=ui->typeE->text();
    int nbrinvit=ui->nbrinvitE->text().toInt();  
    QString endroit=ui->endroitE->text();
    QDate  Date_event = ui->date_Event->date();
    Event E(id,nom,type,nbrinvit,endroit, Date_event);
    E.setid(ui->idE->text().toInt());

   if(E.recherche(E.getid()))
   {
       bool test=E.modifier(id);
   if(test){
       msgbox.setText("modifier avec succes");
   }}else
   msgbox.setText("id introuvable!!");
       msgbox.exec();
}

//fin event


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

void MainWindow::on_BRE_clicked()
{
    Event E;
    QString nom=ui->RECHERCHESE->text();
     ui->tabevent->setModel(E.afficherRSE(nom));
}


void MainWindow::on_pushButton_6_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tabevent->model()->rowCount();
    const int columnCount = ui->tabevent->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=lightblue link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste Des evenements </H1></br></br></tr></tr><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tabevent->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tabevent->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tabevent->isColumnHidden(column))
            {
                QString data = ui->tabevent->model()->data(ui->tabevent->model()->index(row, column)).toString().simplified();
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
