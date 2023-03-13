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

    void on_btn_quitter_clicked();

    void on_btn_gpartenaire_clicked();

    void on_btn_phistorique_clicked();

    void on_btn_retourp_clicked();

    void on_pushButton_valid_14_clicked();

    void on_pushButton_valid_15_clicked();

    void on_BRp_clicked();

    void on_BRS_2_clicked();

    void on_pushButton_6_clicked();

    void on_pdfS_clicked();

    void on_exitb_clicked();

    void on_aff_clicked();

    void on_tabpartenaire_activated(const QModelIndex &index);

    void on_RECHERCHESp_textChanged(const QString &arg1);

    void on_listView_activated(const QModelIndex &index);

    void on_supphistorique_clicked();

    void on_supphistorique_2_clicked();

    void on_pdfhistorique_clicked();

    void on_RECHERCHES_2_textChanged(const QString &arg1);

    void on_tabstock_activated(const QModelIndex &index);

    void on_btn_retourp_2_clicked();

    void on_RECHERCHES_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
