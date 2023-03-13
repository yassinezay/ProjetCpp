#include "partenaire.h"
#include <QObject>
#include <QtDebug>
#include <QMessageBox>
#include <QDateTime>
partenaire::partenaire()
{
id=0 ;
nom="-";
quantite=0;
type="argent";
numtel="-";
somme="-";

}

partenaire::partenaire(int id,QString nom,QString numtel,QString type,int quantite,QString somme,QDateTime Date_convention)
{
    this->id=id;
    this->nom=nom;
    this->quantite=quantite;
    this->type=type;
    this->somme=somme;
    this->numtel=numtel;
    this->Date_convention=Date_convention;
}

bool partenaire::ajouter()
{

QString id_string=QString::number(id);
QString quantite_string=QString::number(quantite);

QSqlQuery query;

     query.prepare("INSERT INTO partenaire (id, nom,numtel,type,quantite,somme,date_convention) "
                   "VALUES (:id, :forename, :numtel, :type, :surname, :somme, :date)");
     query.bindValue(":id", id_string);
     query.bindValue(":forename", nom);
     query.bindValue(":surname", quantite_string);
     query.bindValue(":type", type);
     query.bindValue(":somme", somme);
     query.bindValue(":numtel", numtel);
     query.bindValue(":date", Date_convention);


 return     query.exec();

}

QSqlQueryModel * partenaire::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM partenaire ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num de telephone"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("montant"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("date convention"));


return model;
}

bool partenaire::supprimer(int id)
{

    QSqlQuery query;

         query.prepare("DELETE from partenaire where id=:id ");
         query.bindValue(":id", id);
     return     query.exec();

}
bool partenaire::recherche(int id)
{
    QSqlQuery query;
    int c=0;
    query.prepare("SELECT * from partenaire where id=:id");
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
QSqlQueryModel * partenaire::tri(QString type)
{
QSqlQueryModel * model= new QSqlQueryModel();
QString date="Date";
QString id="Nom";

if(type==date){
    model->setQuery("SELECT * FROM partenaire order by Date_convention ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num de telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date convention"));
}else
{
    model->setQuery("SELECT * FROM partenaire order by nom ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num de telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date convention"));
}



return model;
}
bool partenaire::modifier(int id)
{

QSqlQuery query;


QString id_string=QString::number(id);
QString quantite_string=QString::number(quantite);

query.prepare("UPDATE partenaire SET nom=:nom,numtel=:numtel,type=:type,quantite=:quantite,somme=:somme,Date_convention=:Date_convention WHERE id=:id;");

query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":numtel",numtel);
     query.bindValue(":type",type);
     query.bindValue(":quantite", quantite_string );
     query.bindValue(":somme", somme );
     query.bindValue(":Date_convention", Date_convention );

return    query.exec();
}
QSqlQueryModel * partenaire::afficherRSp(QString id)
{
    QSqlQuery query;

 QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM partenaire WHERE (nom LIKE '%"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num de telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date convention"));

    return model;

}
bool partenaire::ajouter_historique(QString n,QString nom,int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO history (nom, date_historique, nomp, id) "
                  "VALUES (:nom, :date_historique, :nomp, :id)");
    query.bindValue(":nom", n);
    query.bindValue(":date_historique", QDateTime::currentDateTime());
        query.bindValue(":nomp", nom);
            query.bindValue(":id", res);

    return    query.exec();
}
QSqlQueryModel * partenaire::afficher_historique0()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * FROM history");
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat d'historique"));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom partenaire"));


    return model;
    }


QSqlQueryModel * partenaire::afficher_historique(QString type)
{
    QSqlQueryModel * model= new QSqlQueryModel();
     QString a=type;
     if(a=="tout")
     {        model->setQuery("select * FROM history");
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat d'historique"));
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("date"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom partenaire"));}
     else{
        model->setQuery("select * FROM history  WHERE nom LIKE '%"+a+"%'  ");
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat d'historique"));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom partenaire"));

}
    return model;
}

QSqlQueryModel * partenaire::recherchep2(QString a)
{
QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from partenaire WHERE id LIKE '%"+a+"%' OR nom LIKE '%"+a+"%' OR numtel LIKE '%"+a+"%'  OR type LIKE '%"+a+"%' OR date_convention LIKE '%"+a+"%'" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num de telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date convention"));



    return model;}
bool partenaire::supprimerh(int id)
{

    QSqlQuery query;

         query.prepare("DELETE from history where id=:id ");
         query.bindValue(":id", id);
     return     query.exec();

}
