#include "connection.h"

connection::connection()
{

}

bool connection::createConnection()
{
 bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("123456789");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
 return  test;
}
