#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class employe
{
    QString nom,prenom,adresse, designation;
    int id,cin;
public:
    //Constructeur
    employe();
    employe(int ,QString,QString,int ,QString,QString);

    //Getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getID(){return id;}
    QString getAdresse(){return adresse;}
    QString getdesi(){return designation;}
    int getcin(){return cin;}

    //Setters
    void setNom(QString n ){nom=n;}
    void setPrenom(QString n){prenom=n;}
    void setID (int id ){this->id=id; }
    void setdesi(QString n ){designation=n;}
    void setadresse(QString n){adresse=n;}
    void setcin (int cin ){this->cin=cin; }

    //Fonctions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // EMPLOYE_H
