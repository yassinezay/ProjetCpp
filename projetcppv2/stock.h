#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class stock
{
    QString nom , quantite,type;
    QDate d;
    int id;
public:
    stock();
    stock(int,QString,QString,QString,QDate);
    QString getnom(){return nom;}
    QString gettype(){return type;}
    QString getquantite(){return quantite ;}
    int getid(){return id;}
    QDate ged(){return d;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){quantite=p;}
    void setid(int id){this->id=id;}
    void setd(QDate d){this->d=d;}
    bool rechercher(int id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool recherche(int id);
   bool  modifier(int id);
   QSqlQueryModel * afficherRS(QString id);

    QSqlQueryModel * tri(QString type);

};
#endif // STOCK_H
