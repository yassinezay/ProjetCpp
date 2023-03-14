#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include <QDialog>

namespace Ui {
class supprimer;
}

class supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer(QWidget *parent = nullptr);
    ~supprimer();

private:
    Ui::supprimer *ui;
};

#endif // SUPPRIMER_H
