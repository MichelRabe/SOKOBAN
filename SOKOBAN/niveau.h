#ifndef NIVEAU_H
#define NIVEAU_H


#include "plateau.h"

namespace Ui {
class Niveau;
}

class Niveau : public QWidget{
    Q_OBJECT

public:
    explicit Niveau(int lvl, QString fic, int wNiv, int hNiv, int xPlat, int yPlat, int wPlat, int hPlat, int numDecor, int numPerso, QWidget *parent = 0);
    ~Niveau();

public slots:
    void niveauGagne();

signals:
    void signalerVictoireAMainWindow(int m_niveau, int m_nbMvt);

private slots:
    void on_bMenu_clicked();
    void on_bRestart_clicked();
    void on_bAide_clicked();

private:
    Ui::Niveau *ui;

    int m_niveau;
    int m_nbMvt;
    QString m_fichier;
    Plateau *m_plateau;


    void paintEvent(QPaintEvent* e);
    void keyPressEvent(QKeyEvent *event);
};

#endif // NIVEAU_H
