#ifndef PLATEAU_H
#define PLATEAU_H


#include "point.h"

#include "objetvide.h"
#include "objetmur.h"
#include "objetobjectif.h"
#include "objetcaisse.h"
#include "objetpersonnage.h"
#include "objetnull.h"


class Plateau : public QWidget{
    Q_OBJECT

public:
   Plateau(int x=0, int y=0, int w=0, int h=0, QString fic="", int numDecor=1, int numPerso=1, QWidget *parent = 0);
   ~Plateau();

   void keyPressEvent(QKeyEvent *event, int *nbMvt);
   void deplacerPerso(int direction, int *nbMvt);
   bool niveauTermine();
   void recharger(QString fic="");

signals:
   void signalerVictoireANiveau();

private:
    int m_nbLignes;
    int m_nbColonnes;
    int m_largeurCase;
    int m_hauteurCase;

    Point m_posPerso;

    QPixmap* m_dirPerso[4];
    QPixmap *m_perso_vict;

    QPixmap *m_perso;
    QPixmap *m_caisse;
    QPixmap *m_caisse_ok;

    QPixmap *m_vide;
    QPixmap *m_mur;
    QPixmap *m_objectif;

    ObjetImmobile*** m_grilleImmobile;
    ObjetMobile*** m_grilleMobile;

    void paintEvent(QPaintEvent* e);

};

void delay(int millisecondsToWait);

#endif // PLATEAU_H
