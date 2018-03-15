#include "plateau.h"

void delay(int millisecondsToWait){
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime ){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

Plateau::Plateau(int x, int y, int w, int h, QString fic, int numDecor, int numPerso, QWidget *parent):
    QWidget(parent), m_perso(0), m_perso_vict(0), m_vide(0), m_mur(0), m_objectif(0),
    m_caisse(0), m_caisse_ok(0), m_grilleImmobile(0), m_grilleMobile(0){

    for(int i=0; i<4; i++)
        m_dirPerso[i] = 0;

    this->setGeometry(x, y, w, h);
    this->setStyleSheet("background-color:black");



    switch(numDecor){
        case 1:
            m_vide = new QPixmap(":/Images/Photos/vide.jpg");
            m_mur = new QPixmap(":/Images/Photos/mur.png");
            m_objectif = new QPixmap(":/Images/Photos/objectif.jpg");

            m_caisse = new QPixmap(":/Images/Photos/caisse.jpg");
            m_caisse_ok = new QPixmap(":/Images/Photos/caisse_ok.jpg");
        break;
        case 2:
            m_vide = new QPixmap(":/Images/Photos/vide.jpg");
            m_mur = new QPixmap(":/Images/Photos/arbre.png");
            m_objectif = new QPixmap(":/Images/Photos/objectif.jpg");

            m_caisse = new QPixmap(":/Images/Photos/ballon.png");
            m_caisse_ok = new QPixmap(":/Images/Photos/coupe.png");
        break;
    }
    switch(numPerso){
        case 1: {
            QPixmap marioTotal(":/Images/Photos/mario.png");
            m_dirPerso[Haut] = new QPixmap(marioTotal.copy(QRect(0, 69*3, 50, 69)));
            m_dirPerso[Bas] = new QPixmap(marioTotal.copy(QRect(0, 0, 50, 69)));
            m_dirPerso[Gauche] = new QPixmap(marioTotal.copy(QRect(0, 69, 50, 69)));
            m_dirPerso[Droite] = new QPixmap(marioTotal.copy(QRect(0, 69*2, 50, 69)));
            m_perso_vict = new QPixmap(":/Images/Photos/mariovict.png");


            m_perso = m_dirPerso[Bas];
        }
        break;

        case 2:{
            QPixmap zeldaTotal(":/Images/Photos/zelda.png");
            m_dirPerso[Haut] = new QPixmap(zeldaTotal.copy(QRect(0, 100, 50, 50)));
            m_dirPerso[Bas] = new QPixmap(zeldaTotal.copy(QRect(0, 150, 50, 50)));
            m_dirPerso[Gauche] = new QPixmap(zeldaTotal.copy(QRect(0, 50, 50, 50)));
            m_dirPerso[Droite] = new QPixmap(zeldaTotal.copy(QRect(0, 0, 50, 50)));
            m_perso_vict = new QPixmap(":/Images/Photos/zeldavict.png");

            m_perso = m_dirPerso[Bas];
        break;
        }
    }


    QFile fichier(fic);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    flux >> m_nbLignes >> m_nbColonnes;
    //qDebug() << m_nbLignes << m_nbColonnes;

    m_largeurCase = w/m_nbColonnes;
    m_hauteurCase = h/m_nbLignes;

    m_grilleImmobile = new ObjetImmobile**[m_nbLignes];
    for(int i=0; i<m_nbLignes; i++)
        m_grilleImmobile[i] = new ObjetImmobile*[m_nbColonnes];

    m_grilleMobile = new ObjetMobile**[m_nbLignes];
    for(int i=0; i<m_nbLignes; i++)
        m_grilleMobile[i] = new ObjetMobile*[m_nbColonnes];

    QString ligneTmp = flux.readLine();
    for(int i=0; i<m_nbLignes; i++){
        ligneTmp = flux.readLine();
        //qDebug() << ligneTmp;
        for(int j=0; j<m_nbColonnes; j++){
            switch(ligneTmp[j].unicode()){
                case '#':       // Mur
                    m_grilleImmobile[i][j] = new ObjetMur(Point(i,j), m_mur);
                    m_grilleMobile[i][j] = new ObjetNull(); // Rien a dessiner
                break;
                case ' ':       // Vide
                    m_grilleImmobile[i][j] = new ObjetVide(Point(i,j), m_vide);
                    m_grilleMobile[i][j] = new ObjetNull(); // Rien a dessiner
                break;
                case '.':       // Objectif seul
                    m_grilleImmobile[i][j] = new ObjetObjectif(Point(i,j), m_objectif);
                    m_grilleMobile[i][j] = new ObjetNull(); // Rien a dessiner
                break;
                case '$':       // Caisse seule
                    m_grilleImmobile[i][j] = new ObjetVide(Point(i,j), m_vide);
                    m_grilleMobile[i][j] = new ObjetCaisse(Point(i,j), m_caisse);
                break;
                case '@':       // Personnage seul
                    m_posPerso = Point(j,i);
                    m_grilleImmobile[i][j] = new ObjetVide(Point(i,j), m_vide);
                    m_grilleMobile[i][j] = new ObjetPersonnage(Point(i,j), m_perso);
                break;
                case '*':       // Caisse sur objectif
                    m_grilleImmobile[i][j] = new ObjetObjectif(Point(i,j), m_objectif);
                    m_grilleMobile[i][j] = new ObjetCaisse(Point(i,j), m_caisse_ok);
                break;
                case '+':       // Personnage sur objectif
                    m_posPerso = Point(j,i);
                    m_grilleImmobile[i][j] = new ObjetObjectif(Point(i,j), m_objectif);
                    m_grilleMobile[i][j] = new ObjetPersonnage(Point(i,j), m_perso);
                break;
            }
        }
    }

}

Plateau::~Plateau(){
    //qDebug() << "Debut destructeur Plateau";
    m_perso = 0;
    delete m_caisse; m_caisse=0;
    delete m_caisse_ok; m_caisse_ok=0;
    delete m_vide; m_vide=0;
    delete m_mur; m_mur=0;
    delete m_objectif; m_objectif=0;
    delete m_perso_vict; m_perso_vict=0;

    for(int i=0; i<4; i++){
        delete m_dirPerso[i];
        m_dirPerso[i] = 0;
    }


    for(int i=0; i<m_nbLignes; i++){
        for(int j=0; j<m_nbColonnes; j++){
            delete m_grilleImmobile[i][j]; m_grilleImmobile[i][j] = 0;
            delete m_grilleMobile[i][j]; m_grilleMobile[i][j] = 0;
        }
    }

    for(int i=0; i<m_nbLignes; i++){
        delete[] m_grilleImmobile[i]; m_grilleImmobile[i] = 0;
        delete[] m_grilleMobile[i]; m_grilleMobile[i] = 0;
    }

    delete[] m_grilleImmobile; m_grilleImmobile=0;
    delete[] m_grilleMobile; m_grilleMobile=0;
    //qDebug() << "Fin destructeur Plateau";
}

void Plateau::paintEvent(QPaintEvent *e){
    //qDebug() << "Debut painter Plateau";
    QWidget::paintEvent(e);
    QPainter painter(this);

    painter.fillRect(0,0,this->width(),this->height(), QBrush(QColor(99,193,94)));
    for(int i=0; i<m_nbLignes; i++){
        for(int j=0; j<m_nbColonnes; j++){
            painter.drawPixmap(j * m_largeurCase , i * m_hauteurCase, m_largeurCase, m_hauteurCase, m_grilleImmobile[i][j]->getImage());
            if(m_grilleMobile[i][j]->getType() != Vide)
                painter.drawPixmap(j * m_largeurCase , i * m_hauteurCase, m_largeurCase, m_hauteurCase, m_grilleMobile[i][j]->getImage());
        }
    }
    //qDebug() << "Fin painter Plateau";

}

void Plateau::keyPressEvent(QKeyEvent *event, int *nbMvt){
    switch(event->key()){
        case Qt::Key_D:
            deplacerPerso(Droite, nbMvt);
            repaint();
        break;
        case Qt::Key_Q:
            deplacerPerso(Gauche, nbMvt);
            repaint();
        break;
        case Qt::Key_Z:
            deplacerPerso(Haut, nbMvt);
            repaint();
        break;

        case Qt::Key_S:
            deplacerPerso(Bas, nbMvt);
            repaint();
        break;
    }
}

void Plateau::deplacerPerso(int direction, int *nbMvt){
    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()]->setImage(m_dirPerso[direction]);

    switch(direction){
        case Droite:

            // Si on est sur le bord a droite, on ne bouge pas
            if(m_posPerso.getX() == m_nbColonnes-1)
                break;

            // Si il y a un mur a droite, on ne bouge pas
            if(m_grilleImmobile[m_posPerso.getY()][m_posPerso.getX()+1]->getType() == Mur)
                break;

            // Si il y a une caisse a droite, puis le bord, on ne bouge pas
            if((m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1]->getType() == Caisse) && (m_posPerso.getX() == m_nbColonnes-2))
                break;

            // Si il y a une caisse a droite, puis une caisse ou un mur, on ne bouge pas
            if(m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1]->getType() == Caisse &&
               (m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+2]->getType() == Caisse ||
                m_grilleImmobile[m_posPerso.getY()][m_posPerso.getX()+2]->getType() == Mur))
                break;

            // Sinon on peut bouger
            else{
                (*nbMvt)++;
                // Cas ou le perso deplace une caisse
                if(m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1]->getType() == Caisse){
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+2];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+2] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()]=tmp;

                    if(m_grilleImmobile[m_posPerso.getY()][m_posPerso.getX()+2]->getType() == Objectif){
                        m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+2]->setImage(m_caisse_ok);
                        if(niveauTermine()){
                            m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1]->setImage(m_perso_vict);
                            repaint();
                            QMessageBox::information(NULL, "Victoire", "<strong>Bravo, vous avez termine le niveau !</strong>");
                            emit signalerVictoireANiveau();
                        }
                    }
                    else
                        m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+2]->setImage(m_caisse);
                }
                // Sinon, le perso se deplace seul
                else{
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()+1] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()] = tmp;
                }

                m_posPerso.deplacerDe(1,0);
            }
        break;
        case Gauche:

            if(m_posPerso.getX() == 0)
                break;

            if(m_grilleImmobile[m_posPerso.getY()][m_posPerso.getX()-1]->getType() == Mur)
                break;

            if((m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1]->getType() == Caisse) && (m_posPerso.getX() == 1))
                break;

            if(m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1]->getType() == Caisse &&
               (m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-2]->getType() == Caisse ||
                m_grilleImmobile[m_posPerso.getY()][m_posPerso.getX()-2]->getType() == Mur))
                break;

            else{
                (*nbMvt)++;
                if(m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1]->getType() == Caisse){
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-2];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-2] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()]=tmp;

                    if(m_grilleImmobile[m_posPerso.getY()][m_posPerso.getX()-2]->getType() == Objectif){
                        m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-2]->setImage(m_caisse_ok);
                        if(niveauTermine()){
                            m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1]->setImage(m_perso_vict);
                            repaint();
                            QMessageBox::information(NULL, "Victoire", "<strong>Bravo, vous avez termine le niveau !</strong>");
                            emit signalerVictoireANiveau();
                        }
                    }
                    else
                        m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-2]->setImage(m_caisse);
                }
                else{
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()-1] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()] = tmp;
                }

                m_posPerso.deplacerDe(-1,0);
            }
        break;
        case Bas:

            if(m_posPerso.getY() == m_nbLignes-1)
                break;

            if(m_grilleImmobile[m_posPerso.getY()+1][m_posPerso.getX()]->getType() == Mur)
                break;

            if((m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()]->getType() == Caisse) && (m_posPerso.getY() == m_nbLignes-2))
                break;

            if(m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()]->getType() == Caisse &&
               (m_grilleMobile[m_posPerso.getY()+2][m_posPerso.getX()]->getType() == Caisse ||
                m_grilleImmobile[m_posPerso.getY()+2][m_posPerso.getX()]->getType() == Mur))
                break;

            else{
                (*nbMvt)++;
                if(m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()]->getType() == Caisse){
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()+2][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()+2][m_posPerso.getX()] = m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()]=tmp;

                    if(m_grilleImmobile[m_posPerso.getY()+2][m_posPerso.getX()]->getType() == Objectif){
                        m_grilleMobile[m_posPerso.getY()+2][m_posPerso.getX()]->setImage(m_caisse_ok);
                        if(niveauTermine()){
                            m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()]->setImage(m_perso_vict);
                            repaint();
                            QMessageBox::information(NULL, "Victoire", "<strong>Bravo, vous avez termine le niveau !</strong>");
                            emit signalerVictoireANiveau();
                        }
                    }
                    else
                        m_grilleMobile[m_posPerso.getY()+2][m_posPerso.getX()]->setImage(m_caisse);
                }
                else{
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()+1][m_posPerso.getX()] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()] = tmp;
                }

                m_posPerso.deplacerDe(0,1);
            }
        break;
        case Haut:

            if(m_posPerso.getY() == 0)
                break;

            if(m_grilleImmobile[m_posPerso.getY()-1][m_posPerso.getX()]->getType() == Mur)
                break;

            if((m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()]->getType() == Caisse) && (m_posPerso.getY() == 1))
                break;

            if(m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()]->getType() == Caisse &&
               (m_grilleMobile[m_posPerso.getY()-2][m_posPerso.getX()]->getType() == Caisse ||
                m_grilleImmobile[m_posPerso.getY()-2][m_posPerso.getX()]->getType() == Mur))
                break;

            else{
                (*nbMvt)++;
                if(m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()]->getType() == Caisse){
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()-2][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()-2][m_posPerso.getX()] = m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()]=tmp;

                    if(m_grilleImmobile[m_posPerso.getY()-2][m_posPerso.getX()]->getType() == Objectif){
                        m_grilleMobile[m_posPerso.getY()-2][m_posPerso.getX()]->setImage(m_caisse_ok);
                        if(niveauTermine()){
                            m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()]->setImage(m_perso_vict);
                            repaint();
                            QMessageBox::information(NULL, "Victoire", "<strong>Bravo, vous avez termine le niveau !</strong>");
                            emit signalerVictoireANiveau();
                        }
                    }
                    else
                        m_grilleMobile[m_posPerso.getY()-2][m_posPerso.getX()]->setImage(m_caisse);
                }
                else{
                    ObjetMobile* tmp = m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()-1][m_posPerso.getX()] = m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()];
                    m_grilleMobile[m_posPerso.getY()][m_posPerso.getX()] = tmp;
                }

                m_posPerso.deplacerDe(0,-1);
            }
        break;

    }






}

bool Plateau::niveauTermine(){
    for(int i=0; i<m_nbLignes; i++){
        for(int j=0; j<m_nbColonnes; j++){
            if(m_grilleImmobile[i][j]->getType() == Objectif){
                if(m_grilleMobile[i][j]->getType() != Caisse){
                    return false;
                }
            }
        }
    }
    return true;
}



void Plateau::recharger(QString fic){
    for(int i=0; i<m_nbLignes; i++){
        for(int j=0; j<m_nbColonnes; j++){
            delete m_grilleImmobile[i][j];
            delete m_grilleMobile[i][j];
        }
    }
    QFile fichier(fic);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    QString ligneTmp = flux.readLine();
    for(int i=0; i<m_nbLignes; i++){
        ligneTmp = flux.readLine();
        //qDebug() << ligneTmp;
        for(int j=0; j<m_nbColonnes; j++){
            switch(ligneTmp[j].unicode()){
                case '#':       // Mur
                    m_grilleImmobile[i][j] = new ObjetMur(Point(i,j), m_mur);
                    m_grilleMobile[i][j] = new ObjetNull(); // Rien a dessiner
                break;
                case ' ':       // Vide
                    m_grilleImmobile[i][j] = new ObjetVide(Point(i,j), m_vide);
                    m_grilleMobile[i][j] = new ObjetNull(); // Rien a dessiner
                break;
                case '.':       // Objectif seul
                    m_grilleImmobile[i][j] = new ObjetObjectif(Point(i,j), m_objectif);
                    m_grilleMobile[i][j] = new ObjetNull(); // Rien a dessiner
                break;
                case '$':       // Caisse seule
                    m_grilleImmobile[i][j] = new ObjetVide(Point(i,j), m_vide);
                    m_grilleMobile[i][j] = new ObjetCaisse(Point(i,j), m_caisse);
                break;
                case '@':       // Personnage seul
                    m_posPerso = Point(j,i);
                    m_grilleImmobile[i][j] = new ObjetVide(Point(i,j), m_vide);
                    m_grilleMobile[i][j] = new ObjetPersonnage(Point(i,j), m_perso);
                break;
                case '*':       // Caisse sur objectif
                    m_grilleImmobile[i][j] = new ObjetObjectif(Point(i,j), m_objectif);
                    m_grilleMobile[i][j] = new ObjetCaisse(Point(i,j), m_caisse_ok);
                break;
                case '+':       // Personnage sur objectif
                    m_posPerso = Point(j,i);
                    m_grilleImmobile[i][j] = new ObjetObjectif(Point(i,j), m_objectif);
                    m_grilleMobile[i][j] = new ObjetPersonnage(Point(i,j), m_perso);
                break;
            }
        }
    }
    repaint();
}



