#include "niveau.h"
#include "ui_niveau.h"




Niveau::Niveau(int lvl, QString fic, int wNiv, int hNiv, int xPlat, int yPlat, int wPlat, int hPlat, int numDecor, int numPerso, QWidget *parent) :
    QWidget(parent), ui(new Ui::Niveau), m_plateau(0){

    //qDebug() << "Debut constructeur Niveau";
    ui->setupUi(this);
    this->move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height()) / 2);

    this->setWindowIcon(QIcon(":/Images/Photos/sokobanIcon.png"));
    this->resize(wNiv, hNiv);

    m_niveau = lvl;
    m_plateau = new Plateau(xPlat, yPlat, wPlat, hPlat, fic, numDecor, numPerso, this);
    QObject::connect(m_plateau,SIGNAL(signalerVictoireANiveau()),this,SLOT(niveauGagne()));
    m_nbMvt = 0;
    m_fichier = fic;

    ui->bCompteurMvt->setText("  Nombre mouvements : 0");
    //qDebug() << "Fin constructeur Niveau";

}

Niveau::~Niveau(){
    //qDebug() << "Debut destructeur Niveau";
    delete ui;
    delete m_plateau;
    //qDebug() << "Fin destructeur Niveau";
}

void Niveau::niveauGagne(){
    close();
    emit signalerVictoireAMainWindow(m_niveau, m_nbMvt);
}


void Niveau::paintEvent(QPaintEvent* e){
    //qDebug() << "Debut painter Niveau";
    QWidget::paintEvent(e);
    QPainter painter(this);

    //qDebug() << "Fin painter Niveau";

}

void Niveau::keyPressEvent(QKeyEvent *event){
    //qDebug() << "Debut press Niveau";
    m_plateau->keyPressEvent(event, &m_nbMvt);
    ui->bCompteurMvt->setText("  Nombre mouvements : " + QString::number(m_nbMvt));
    //qDebug() << "Fin press Niveau";
}

void Niveau::on_bMenu_clicked(){
    close();
}

void Niveau::on_bRestart_clicked(){
    m_nbMvt = 0;
    ui->bCompteurMvt->setText("  Nombre mouvements : 0");
    m_plateau->recharger(m_fichier);

}

void Niveau::on_bAide_clicked(){
    QMessageBox::information(NULL, "Aide", "Placez toutes les caisses sur les objectifs. \nDeplacez votre personnage a l'aide des touches q/s/d/z");
}
