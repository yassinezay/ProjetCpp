#include "event.h"
#include <QObject>
#include <QtDebug>
#include <QMessageBox>
Event::Event()
{
id=0 ;
nom="-";
nbrinvit=0;
type="-";
endroit="-";

}

Event::Event(int id,QString nom,QString type,int nbrinvit,QString endroit,QDate  Date_event)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->nbrinvit=nbrinvit;
    this->endroit=endroit;
    this-> Date_event= Date_event;
}

bool Event::ajouter()
{

QString id_string=QString::number(id);
QString nbrinvit_string=QString::number(nbrinvit);

QSqlQuery query;

     query.prepare("INSERT INTO EVENT (ID, NOM,TYPE,NBRINVIT,ENDROIT, DATE_EVENT) "
                   "VALUES (:id, :nom, :type, :nbrinvit, :endroit, :date)");
     query.bindValue(":id", id_string);
     query.bindValue(":nom", nom);
     query.bindValue(":nbrinvit", nbrinvit_string);
     query.bindValue(":type", type);
     query.bindValue(":endroit", endroit);
     query.bindValue(":date", Date_event);


 return     query.exec();

}

QSqlQueryModel * Event::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM EVENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("endroit"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbrinvit"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date event"));


return model;
}

bool Event::supprimer(int id)
{

    QSqlQuery query;

         query.prepare("DELETE from EVENT where id=:id ");
         query.bindValue(":id", id);
     return     query.exec();

}
bool Event::recherche(int id)
{
    QSqlQuery query;
    int c=0;
    query.prepare("SELECT * from Event where id=:id");
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
QSqlQueryModel * Event::tri(QString type)
{
QSqlQueryModel * model= new QSqlQueryModel();
QString date="Date";
QString id="Nom";

if(type==date){
    model->setQuery("SELECT * FROM Event order by Date_convention ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("endroit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbrinvit"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date event"));
}else
{
    model->setQuery("SELECT * FROM EVENT order by id DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("endroit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbrinvit"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date event"));
}



return model;
}
bool Event::modifier(int id)
{

QSqlQuery query;


QString id_string=QString::number(id);
QString nbrinvit_string=QString::number(nbrinvit);

query.prepare("UPDATE Event SET nom=:nom,type=:type,nbrinvit=:nbrinvit,endroit=:endroit,Date_event=:Date_event WHERE id=:id;");

query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":type",type);
     query.bindValue(":nbrinvit", nbrinvit_string );
     query.bindValue(":endroit", endroit );
     query.bindValue(":Date_event", Date_event );

return    query.exec();
}
QSqlQueryModel * Event::afficherRSE(QString id)
{
    QSqlQuery query;

 QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EVENT WHERE (nom LIKE '%"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("endroit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbrinvit"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date event"));

    return model;

}
