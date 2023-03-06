#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QDate>

class partenaire
{
    QString nom,type,numtel,somme,Date_convention;

    int id,quantite;
public:
    partenaire();
    partenaire(int,QString,QString,QString,int,QString,QString);
    QString getnom(){return nom;}
    QString gettype(){return type;}
    int getquantite(){return quantite ;}
    QString getsomme(){return somme ;}
    QString getnumtel(){return numtel ;}
    QString getdate(){return Date_convention ;}
    int getid(){return id;}
    void setnom(QString n){nom=n;}
    void setprenom(int p){quantite=p;}
    void setid(int id){this->id=id;}
    void setnumtel(QString numtel){this->numtel=numtel;}
    void setsomme(QString s){somme=s;}
    QString setdate(){return Date_convention ;}
    bool rechercher(int id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool recherche(int id);
    QSqlQueryModel * tri(QString type);
    bool modifier(int id);





};
#endif
