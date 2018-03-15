#include "configniveau.h"
#include "ui_configniveau.h"

ConfigNiveau::ConfigNiveau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigNiveau)
{
    ui->setupUi(this);

    this->setWindowTitle("CONFIGURATION");
    ui->bMario_2->setChecked(true);
    ui->bMur->setChecked(true);

}

ConfigNiveau::~ConfigNiveau()
{
    delete ui;
}


void ConfigNiveau::changerDecor(){

}

int ConfigNiveau::getPerso(){
    return m_numPerso;
}

int ConfigNiveau::getDecor(){
    return m_numDecor;
}

void ConfigNiveau::on_buttonBox_accepted()
{
    if(ui->bMario_2->isChecked()){
        m_numPerso=1;
    }
    if(ui->bZelda_2->isChecked()){
        m_numPerso=2;
    }

    if(ui->bMur->isChecked()){
        m_numDecor=1;
    }
    if(ui->bArbre->isChecked()){
        m_numDecor=2;
    }

}
