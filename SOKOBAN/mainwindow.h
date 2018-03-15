#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>

#include "niveau.h"
#include "configniveau.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_bNiv1_clicked();  
    void on_bNiv2_clicked();
    void on_bNiv3_clicked();
    void on_bNiv4_clicked();
    void on_bNiv5_clicked();
    void on_bNiv6_clicked();
    void on_bNiv7_clicked();
    void on_bNiv8_clicked();
    void on_bNiv9_clicked();
    void on_bNiv10_clicked();

    void niveauRemporte(int lvl, int nbMvt);

     void on_bConfig_clicked();

     void on_actionPartie_triggered();

     void on_actionR_gle_du_jeu_triggered();

     void on_bSuivant_clicked();

     void on_bPrecedent_clicked();

     void on_bNiveau_clicked();

private:
    Ui::MainWindow *ui;
    Niveau *m_niv;

    int m_niveauDebloque;
    int m_mvtMin[10];

    int m_numDecor;
    int m_numPerso;


    void paintEvent(QPaintEvent* e);


};

#endif // MAINWINDOW_H
