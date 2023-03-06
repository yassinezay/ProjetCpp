#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_ogrenci_5_clicked();

    void on_pushButton_clicked();

    void on_btn_ogrenci_6_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_validers_clicked();

    void on_supprstock_clicked();

    void on_pushButton_valid_10_clicked();

    void on_pushButton_valid_13_clicked();

    void on_validpartenaire_clicked();

    void on_pushButton_valid_16_clicked();

    void on_supp_partenaire_clicked();

    void on_pushButton_valid_18_clicked();

    void on_selectri_activated(const QString &arg1);

    void on_modifierp_clicked();

    void on_treeStock_clicked();

    void on_modifierStock_clicked();

    void on_pushButton_valid_11_clicked();

    void on_BRS_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
