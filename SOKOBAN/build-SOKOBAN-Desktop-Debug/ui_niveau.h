/********************************************************************************
** Form generated from reading UI file 'niveau.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEAU_H
#define UI_NIVEAU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Niveau
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *bMenu;
    QPushButton *bRestart;
    QPushButton *bAide;
    QLabel *bCompteurMvt;

    void setupUi(QWidget *Niveau)
    {
        if (Niveau->objectName().isEmpty())
            Niveau->setObjectName(QStringLiteral("Niveau"));
        Niveau->resize(1080, 709);
        Niveau->setAutoFillBackground(false);
        Niveau->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        verticalLayoutWidget = new QWidget(Niveau);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(860, 100, 160, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bMenu = new QPushButton(verticalLayoutWidget);
        bMenu->setObjectName(QStringLiteral("bMenu"));

        verticalLayout->addWidget(bMenu);

        bRestart = new QPushButton(verticalLayoutWidget);
        bRestart->setObjectName(QStringLiteral("bRestart"));

        verticalLayout->addWidget(bRestart);

        bAide = new QPushButton(verticalLayoutWidget);
        bAide->setObjectName(QStringLiteral("bAide"));

        verticalLayout->addWidget(bAide);

        bCompteurMvt = new QLabel(Niveau);
        bCompteurMvt->setObjectName(QStringLiteral("bCompteurMvt"));
        bCompteurMvt->setGeometry(QRect(260, 20, 371, 61));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Serif"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        bCompteurMvt->setFont(font);
        bCompteurMvt->setStyleSheet(QLatin1String("background-color: rgb(34, 0, 255);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Niveau);

        QMetaObject::connectSlotsByName(Niveau);
    } // setupUi

    void retranslateUi(QWidget *Niveau)
    {
        Niveau->setWindowTitle(QApplication::translate("Niveau", "Form", Q_NULLPTR));
        bMenu->setText(QApplication::translate("Niveau", "Menu", Q_NULLPTR));
        bRestart->setText(QApplication::translate("Niveau", "Restart", Q_NULLPTR));
        bAide->setText(QApplication::translate("Niveau", "Aide", Q_NULLPTR));
        bCompteurMvt->setText(QApplication::translate("Niveau", " Compteur mouvements : 0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Niveau: public Ui_Niveau {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEAU_H
