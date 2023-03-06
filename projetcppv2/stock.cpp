#include "stock.h"
#include <QObject>
#include <QtDebug>
#include <QMessageBox>
#include<QDate>
stock::stock()
{
id=0 ;
nom=" ";
quantite="0";
type=" ";
}

stock::stock(int id,QString nom,QString prenom,QString type,QDate d)
{
    this->id=id;
    this->nom=nom;
    this->quantite=prenom;
    this->type=type;
    this->d=d;
}

bool stock::ajouter()
{

QString id_string=QString::number(id);
QSqlQuery query;

     query.prepare("INSERT INTO STOCK (id, nom,quantite,type,dates) "
                   "VALUES (:id, :forename, :surname, :type, :date)");
     query.bindValue(":id", id_string);
     query.bindValue(":forename", nom);
     query.bindValue(":surname", quantite);
     query.bindValue(":type", type);
     query.bindValue(":date", d);

 return     query.exec();

}

QSqlQueryModel * stock::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM stock");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));

return model;
}

bool stock::supprimer(int id)
{

    QSqlQuery query;

         query.prepare("DELETE from stock where id=:id ");
         query.bindValue(":id", id);
     return     query.exec();

}
bool stock::recherche(int id)
{
    QSqlQuery query;
    int c=0;
    query.prepare("SELECT *from stock where id=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        while(query.next())
        {
            c++;
        }

        if(c==1)
        {
            QMessageBox boxt;
            boxt.setText("trouvé");
            return true;

        }


    }
    return false;

}


QSqlQueryModel * stock::tri(QString type)
{
QSqlQueryModel * model= new QSqlQueryModel();
QString date="Date";
QString id="Nom";

if(type==date){
    model->setQuery("SELECT * FROM stock order by dates DESC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
}else
{
    model->setQuery("SELECT * FROM stock order by id DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
}



return model;
}
bool stock::modifier(int id)
{

QSqlQuery query;


QString id_string=QString::number(id);

query.prepare("UPDATE stock SET nom=:nom,type=:type,quantite=:quantite,dates=:dates WHERE id=:id;");

query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":type",type);
     query.bindValue(":quantite", quantite );
     query.bindValue(":dates", d );

return    query.exec();
}

QSqlQueryModel * stock::afficherRS(int n)
{
    QSqlQuery query;
    QString n_string=QString::number(n);
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM stock WHERE id=:n;");
     query.bindValue(":n", n_string );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
return model;

}
