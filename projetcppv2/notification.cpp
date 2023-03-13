#include "notification.h"


void notification::notification_ajout()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/ASUS/Desktop/projetcppv5/images/notification.png"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Careness"," un nouveau partenaire a été ajouter !",QSystemTrayIcon::Information,15000);

}
