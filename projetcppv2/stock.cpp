#include "stock.h"
#include <QObject>
#include <QtDebug>
#include <QMessageBox>
stock::stock()
{
id=0 ;
nom=" ";
quantite="0";
type=" ";
}

stock::stock(int id,QString nom,QString prenom,QString type)
{
    this->id=id;
    this->nom=nom;
    this->quantite=prenom;
    this->type=type;
}

bool stock::ajouter()
{

QString id_string=QString::number(id);
QSqlQuery query;

     query.prepare("INSERT INTO STOCK (id, nom,quantite,type) "
                   "VALUES (:id, :forename, :surname, :type)");
     query.bindValue(":id", id_string);
     query.bindValue(":forename", nom);
     query.bindValue(":surname", quantite);
     query.bindValue(":type", type);
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
