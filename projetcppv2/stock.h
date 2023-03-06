#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class stock
{
    QString nom , quantite,type;

    int id;
public:
    stock();
    stock(int,QString,QString,QString);
    QString getnom(){return nom;}
    QString gettype(){return type;}
    QString getquantite(){return quantite ;}
    int getid(){return id;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){quantite=p;}
    void setid(int id){this->id=id;}
    bool rechercher(int id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool recherche(int id);

};
#endif // STOCK_H
