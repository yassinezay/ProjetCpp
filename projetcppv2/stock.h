#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class stock
{
    QString nom , quantite,type;
    QDateTime d;
    int id;
public:
    stock();
    stock(int,QString,QString,QString,QDateTime);
    QString getnom(){return nom;}
    QString gettype(){return type;}
    QString getquantite(){return quantite ;}
    int getid(){return id;}
    QDateTime ged(){return d;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){quantite=p;}
    void setid(int id){this->id=id;}
    void setd(QDateTime d){this->d=d;}
    bool rechercher(int id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool recherche(int id);
   bool  modifier(int id);
   QSqlQueryModel * afficherRS(QString id);

    QSqlQueryModel * tri(QString type);
    QSqlQueryModel * recherches2(QString a);


};
#endif // STOCK_H
