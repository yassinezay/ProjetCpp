#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QDate>

class Event
{
    QString nom,type,endroit;
    QDate Date_event;

    int id,nbrinvit;
public:
    Event();
    Event(int,QString,QString,int,QString,QDate);
    QString getnom(){return nom;}
    QString gettype(){return type;}
    int getnbrinvit(){return nbrinvit ;}
    QString getendroit(){return endroit ;}
    QDate getdate(){return Date_event ;}
    int getid(){return id;}

    void setnom(QString n){nom=n;}
    void settype(QString t){type=t;}
    void setprenom(int p){nbrinvit=p;}
    void setid(int id){this->id=id;}
    void setendroit(QString s){endroit=s;}
    void setdate(QDate d){ Date_event=d ;}

    bool rechercher(int id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool recherche(int id);
    QSqlQueryModel * tri(QString type);
    bool modifier(int id);
    QSqlQueryModel * afficherRSE(QString id);






};
#endif
