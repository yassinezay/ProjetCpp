#include "employe.h"

employe::employe(){
    id=0;
    nom="";
    prenom="";
    adresse="";
    designation="";
    cin=0;
}

employe::employe(int id ,QString nom,QString prenom ,int cin ,QString adresse,QString designation)

{
    this->id=id;
    this->nom=nom;
    this ->prenom=prenom;
    this->adresse=adresse;
    this->designation=designation;
    this->cin=cin;
}

bool employe::ajouter(){

    QString id_string=QString::number(id);
    QString CIN_string=QString::number(cin);

    QSqlQuery query;

         query.prepare("INSERT INTO employe (id, nom, prenom,cin,designation,adresse) "
                       "VALUES (:id, :nom, :prenom,:cin,:designation,:adresse)");
         query.bindValue(":id", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":cin", CIN_string);
         query.bindValue(":designation", designation);
         query.bindValue(":adresse", adresse);


     return     query.exec();

}

QSqlQueryModel * employe::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Designation"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Adresse"));


    return model;
}
bool employe::supprimer(int id){
    QSqlQuery query;
          query.prepare("DELETE from employe where id=:id ");
          query.bindValue(":id", id);
      return     query.exec();
}

bool employe::modifier(int id)
{

QSqlQuery query;


QString id_string=QString::number(id);
QString CIN_string=QString::number(cin);

query.prepare("UPDATE employe SET nom=:nom,prenom=:prenom,cin=:cin,adresse=:adresse,designation=:designation WHERE id=:id;");

query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":cin", CIN_string );
     query.bindValue(":adresse", adresse );
     query.bindValue(":designation", designation );


return    query.exec();
}

bool employe::recherche(int id)
{
    QSqlQuery query;
    int c=0;
    query.prepare("SELECT * from employe where id=:id");
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
