#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QDateTime>

class partenaire
{
    QString nom,type,numtel,somme;
    QDateTime Date_convention;

    int id,quantite;
public:
    partenaire();
    partenaire(int,QString,QString,QString,int,QString,QDateTime);
    QString getnom(){return nom;}
    QString gettype(){return type;}
    int getquantite(){return quantite ;}
    QString getsomme(){return somme ;}
    QString getnumtel(){return numtel ;}
    QDateTime getdate(){return Date_convention ;}
    int getid(){return id;}
    void setnom(QString n){nom=n;}
    void setprenom(int p){quantite=p;}
    void setid(int id){this->id=id;}
    void setnumtel(QString numtel){this->numtel=numtel;}
    void setsomme(QString s){somme=s;}
    void setdate(QDateTime d){ Date_convention=d ;}
    bool rechercher(int id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool recherche(int id);
    QSqlQueryModel * tri(QString type);
    bool modifier(int id);
    QSqlQueryModel * afficherRSp(QString id);
    bool ajouter_historique(QString n,QString nom,int id);
    QSqlQueryModel * afficher_historique(QString type);
    QSqlQueryModel * afficher_historique0();
    QSqlQueryModel * recherchep2(QString a);
    bool supprimerh(int id);







};
#endif
