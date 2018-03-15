#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), m_niv(0), m_niveauDebloque(1), m_numDecor(1), m_numPerso(1){

    ui->setupUi(this);
    this->move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height()) / 2);

    QPixmap cadenasFerme(":/Images/Photos/cadenasFerme.png");
    QPixmap cadenasOuvert(":/Images/Photos/cadenasOuvert.png");

    this->setWindowIcon(QIcon(":/Images/Photos/sokobanIcon.png"));
    this->setWindowTitle("SOKOBAN");

    this->ui->titreJeu->setFont(QFont("Arial", 55, 5, true));
    this->ui->titreJeu->setStyleSheet("color: #FF0000; text-decoration: underline; background-color:#F0F0F0");
    this->ui->titreJeu->setAlignment(Qt::AlignCenter);



    this->ui->bNiv2->setEnabled(false);
    this->ui->bNiv3->setEnabled(false);
    this->ui->bNiv4->setEnabled(false);
    this->ui->bNiv5->setEnabled(false);
    this->ui->bNiv6->setEnabled(false);
    this->ui->bNiv7->setEnabled(false);
    this->ui->bNiv8->setEnabled(false);
    this->ui->bNiv9->setEnabled(false);
    this->ui->bNiv10->setEnabled(false);

    //qDebug() << ui->bTps2->width() << ui->bTps2->height();
    //qDebug() << ui->bTps2->geometry().width() << ui->bTps2->geometry().height();

    int w = 151, h=133;
    this->ui->labNiv1->setPixmap(cadenasOuvert.scaled(w, h));
    this->ui->labNiv2->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv3->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv4->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv5->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv6->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv7->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv8->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv9->setPixmap(cadenasFerme.scaled(w, h));
    this->ui->labNiv10->setPixmap(cadenasFerme.scaled(w, h));

    //QMediaPlayer * music = new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/Sounds/BO2.mp3"));
    //music->play();

    this->ui->labNiveau->setPixmap(cadenasOuvert.scaled(50, 50));

    //*********************************************
    QString niveau, niv1;
    niveau=this->ui->bNiveau->text();
    int i=niveau.size();
    for(int i=7;i<niveau.size();i++){
        niv1[i]=niveau[i];
    }
    //niveau.remove(i);
    int niv;
    niv=niv1.toInt();
    if(niv==1){
        this->ui->bNiveau->setEnabled(true);
    }
    else{
        this->ui->bNiveau->setEnabled(false);
    }
    //***********************************************
}

MainWindow::~MainWindow(){
    delete ui;
    if(m_niv != 0)
        delete m_niv;
}




void MainWindow::on_bNiv1_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }

    // Modification  dynamique***********
    QString niveau, niv1;
    niveau=ui->bNiv1->text();
    int i=niveau.size();
    for(int i=7;i<niveau.size();i++){
        niv1[i]=niveau[i];
    }
    //niveau.remove(i);
    int niv;
    niv=niv1.toInt();

    QString fichier, num;//, partie=":/Niveaux/Levels/level", txt=".txt";
    num=QString::number(niv);
    fichier.append(":/Niveaux/Levels/level");// partie % niveau % txt ;
    fichier.append(num);
    fichier.append(".txt");
   // ui->bNiv2->setText(niv1);
    //********************************

    m_niv = new Niveau(niv, fichier , 1080, 710, 200, 100, 480, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));
    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 1");
    m_niv->show();

}

void MainWindow::on_bNiv2_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(2, ":/Niveaux/Levels/level2.txt", 1080, 710, 200, 100, 480, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 2");
    m_niv->show();
}

void MainWindow::on_bNiv3_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(3, ":/Niveaux/Levels/level3.txt", 1080, 710, 200, 100, 480, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 3");
    m_niv->show();
}

void MainWindow::on_bNiv4_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(4, ":/Niveaux/Levels/level4.txt", 1080, 710, 200, 100, 480, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 4");
    m_niv->show();
}

void MainWindow::on_bNiv5_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(5, ":/Niveaux/Levels/level5.txt", 1080, 710, 200, 100, 480, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 5");
    m_niv->show();
}

void MainWindow::on_bNiv6_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(6, ":/Niveaux/Levels/level6.txt", 1080, 710, 300, 100, 300, 600, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 6");
    m_niv->show();
}

void MainWindow::on_bNiv7_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(7, ":/Niveaux/Levels/level7.txt", 1080, 710, 200, 100, 560, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 7");
    m_niv->show();
}

void MainWindow::on_bNiv8_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(8, ":/Niveaux/Levels/level8.txt", 1080, 710, 200, 100, 480, 360, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 8");
    m_niv->show();
}

void MainWindow::on_bNiv9_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(9, ":/Niveaux/Levels/level9.txt", 1080, 710, 300, 100, 300, 550, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 9");
    m_niv->show();
}

void MainWindow::on_bNiv10_clicked(){
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }
    m_niv = new Niveau(10, ":/Niveaux/Levels/level10.txt", 1080, 710, 200, 100, 480, 420, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));

    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau 10");
    m_niv->show();
}

void MainWindow::paintEvent(QPaintEvent* e){
    QWidget::paintEvent(e);
    QPainter painter(this);

    painter.fillRect(0, 0, this->width(), this->height(), QBrush(QColor(105,173,239), Qt::Dense3Pattern));
}


void MainWindow::niveauRemporte(int lvl, int nbMvt){
    int w = 151, h=133;

    switch(lvl){
        case 1:
            if(lvl != m_niveauDebloque){
                if(nbMvt < m_mvtMin[lvl-1]){
                    m_mvtMin[lvl-1] = nbMvt;
                    ui->labNiv1->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
                }
            }
            else{
                m_mvtMin[lvl-1] = nbMvt;
                m_niveauDebloque++;
                ui->labNiv1->setStyleSheet("background:#FFFFFF; color:#FF0000; text-decoration: underline");
                ui->labNiv1->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
                ui->labNiv2->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
                ui->bNiv2->setEnabled(true);
            }
        break;

        case 2:
            if(lvl != m_niveauDebloque){
                if(nbMvt < m_mvtMin[lvl-1]){
                    m_mvtMin[lvl-1] = nbMvt;
                    ui->labNiv2->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
                }
            }
            else{
                m_mvtMin[lvl-1] = nbMvt;
                m_niveauDebloque++;
                ui->labNiv2->setStyleSheet("background:#FFFFFF; color:#FF0000; text-decoration: underline");
                ui->labNiv2->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
                ui->labNiv3->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
                ui->bNiv3->setEnabled(true);
            }
        break;

        case 3:
            if(lvl != m_niveauDebloque){
                if(nbMvt < m_mvtMin[lvl-1]){
                    m_mvtMin[lvl-1] = nbMvt;
                    ui->labNiv3->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
                }
            }
            else{
                m_mvtMin[lvl-1] = nbMvt;
                m_niveauDebloque++;
                ui->labNiv3->setStyleSheet("background:#FFFFFF; color:#FF0000; text-decoration: underline");
                ui->labNiv3->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
                ui->labNiv4->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
                ui->bNiv4->setEnabled(true);
            }
        break;

        case 4:
            if(lvl != m_niveauDebloque){
                if(nbMvt < m_mvtMin[lvl-1]){
                    m_mvtMin[lvl-1] = nbMvt;
                    ui->labNiv4->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
                }
            }
            else{
                m_mvtMin[lvl-1] = nbMvt;
                m_niveauDebloque++;
                ui->labNiv4->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
                ui->labNiv5->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
                ui->bNiv5->setEnabled(true);
            }
        break;

        case 5:
        if(lvl != m_niveauDebloque){
            if(nbMvt < m_mvtMin[lvl-1]){
                m_mvtMin[lvl-1] = nbMvt;
                ui->labNiv5->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
            }
        }
        else{
            m_mvtMin[lvl-1] = nbMvt;
            m_niveauDebloque++;
            ui->labNiv5->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
            ui->labNiv6->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
            ui->bNiv6->setEnabled(true);
        }

        break;
        case 6:
        if(lvl != m_niveauDebloque){
            if(nbMvt < m_mvtMin[lvl-1]){
                m_mvtMin[lvl-1] = nbMvt;
                ui->labNiv6->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
            }
        }
        else{
            m_mvtMin[lvl-1] = nbMvt;
            m_niveauDebloque++;
            ui->labNiv6->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
            ui->labNiv7->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
            ui->bNiv7->setEnabled(true);
        }

        break;
        case 7:
        if(lvl != m_niveauDebloque){
            if(nbMvt < m_mvtMin[lvl-1]){
                m_mvtMin[lvl-1] = nbMvt;
                ui->labNiv7->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
            }
        }
        else{
            m_mvtMin[lvl-1] = nbMvt;
            m_niveauDebloque++;
            ui->labNiv7->setText("Top score :\n\n"  + QString::number(nbMvt) + " mouvements");
            ui->labNiv8->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
            ui->bNiv8->setEnabled(true);
        }

        break;
        case 8:
        if(lvl != m_niveauDebloque){
            if(nbMvt < m_mvtMin[lvl-1]){
                m_mvtMin[lvl-1] = nbMvt;
                ui->labNiv8->setText("Top score :\n\n"  + QString::number(m_mvtMin[lvl-1]) + " mouvements");
            }
        }
        else{
            m_mvtMin[lvl-1] = nbMvt;
            m_niveauDebloque++;
            ui->labNiv8->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
            ui->labNiv9->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
            ui->bNiv9->setEnabled(true);
        }

        break;
        case 9:
        if(lvl != m_niveauDebloque){
            if(nbMvt < m_mvtMin[lvl-1]){
                m_mvtMin[lvl-1] = nbMvt;
                ui->labNiv9->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
            }
        }
        else{
            m_mvtMin[lvl-1] = nbMvt;
            m_niveauDebloque++;
            ui->labNiv9->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
            ui->labNiv10->setPixmap(QPixmap(":/Images/Photos/cadenasOuvert.png").scaled(w, h));
            ui->bNiv10->setEnabled(true);
        }

        break;
        case 10:
        if(lvl != m_niveauDebloque){
            if(nbMvt < m_mvtMin[lvl-1]){
                m_mvtMin[lvl-1] = nbMvt;
                ui->labNiv10->setText("Top score :\n\n" + QString::number(m_mvtMin[lvl-1]) + " mouvements");
            }
        }
        else{
            m_mvtMin[lvl-1] = nbMvt;
            m_niveauDebloque++;
            ui->labNiv10->setText("Top score :\n\n" + QString::number(nbMvt) + " mouvements");
            QMessageBox::information(NULL, "Fin du jeu", "Felicitation, vous avez termine tous les niveaux du jeu ! ");
        }
        break;
    }
}

void MainWindow::on_bConfig_clicked()
{
    ConfigNiveau config(this);

    if(config.exec()==QDialog::Accepted){
        this->m_numPerso=config.getPerso();
        this->m_numDecor=config.getDecor();
    }
}

void MainWindow::on_actionPartie_triggered()
{
    MainWindow::on_bConfig_clicked();
}

void MainWindow::on_actionR_gle_du_jeu_triggered()
{
    QMessageBox::information(NULL, "Aide", "Placez toutes les caisses sur les objectifs. \nDeplacez votre personnage a l'aide des touches q/s/d/z");
}

void MainWindow::on_bSuivant_clicked()
{
   QString niveau, niv1,nouveau;
   niveau=ui->bNiveau->text();
   for(int i=7;i<niveau.size();i++){
       niv1[i]=niveau[i];
   }
   //niveau.remove(i);
   int niv;
   niv=niv1.toInt();
   niv=niv+1;
   nouveau="Niveau "+ QString::number(niv);
    ui->bNiveau->setText(nouveau);
}

void MainWindow::on_bPrecedent_clicked()
{

    QString niveau, niv1,nouveau;
    niveau=ui->bNiveau->text();
    for(int i=7;i<niveau.size();i++){
        niv1[i]=niveau[i];
    }
    //niveau.remove(i);
    int niv;
    niv=niv1.toInt();
    if (niv>1){
        niv=niv-1;
        nouveau="Niveau "+ QString::number(niv);
         ui->bNiveau->setText(nouveau);
    }
}

void MainWindow::on_bNiveau_clicked()
{
    if(m_niv != 0){
        delete m_niv;
        m_niv = 0;
    }

    // Modification  dynamique***********
    QString niveau, niv1;
    niveau=ui->bNiveau->text();
    int i=niveau.size();
    for(int i=7;i<niveau.size();i++){
        niv1[i]=niveau[i];
    }
    //niveau.remove(i);
    int niv;
    niv=niv1.toInt();

    QString fichier, num;//, partie=":/Niveaux/Levels/level", txt=".txt";
    num=QString::number(niv);
    fichier.append(":/Niveaux/Levels/level");// partie % niveau % txt ;
    fichier.append(num);
    fichier.append(".txt");
   // ui->bNiv2->setText(niv1);
    //********************************

    m_niv = new Niveau(niv, fichier , 1080, 710, 200, 100, 480, 480, m_numDecor, m_numPerso);
    QObject::connect(m_niv, SIGNAL(signalerVictoireAMainWindow(int,int)), this, SLOT(niveauRemporte(int,int)));
    m_niv->setWindowModality(Qt::ApplicationModal);
    m_niv->setWindowTitle("Niveau"+num);
    m_niv->show();
}
