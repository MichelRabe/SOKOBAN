/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *titreJeu;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labNiv7;
    QPushButton *bNiv8;
    QLabel *labNiv1;
    QPushButton *bNiv6;
    QPushButton *bNiv7;
    QLabel *labNiv4;
    QLabel *labNiv5;
    QPushButton *bNiv10;
    QPushButton *bNiv4;
    QLabel *labNiv8;
    QLabel *labNiv2;
    QLabel *labNiv3;
    QPushButton *bNiv9;
    QPushButton *bNiv5;
    QLabel *labNiv9;
    QPushButton *bNiv3;
    QLabel *labNiv6;
    QPushButton *bNiv1;
    QLabel *labNiv10;
    QPushButton *bNiv2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1070, 697);
        MainWindow->setMinimumSize(QSize(211, 0));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        titreJeu = new QLabel(centralWidget);
        titreJeu->setObjectName(QStringLiteral("titreJeu"));
        titreJeu->setGeometry(QRect(280, 30, 481, 91));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(10);
        titreJeu->setFont(font);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 220, 781, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labNiv7 = new QLabel(gridLayoutWidget);
        labNiv7->setObjectName(QStringLiteral("labNiv7"));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Serif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        labNiv7->setFont(font1);

        gridLayout->addWidget(labNiv7, 4, 1, 1, 1);

        bNiv8 = new QPushButton(gridLayoutWidget);
        bNiv8->setObjectName(QStringLiteral("bNiv8"));
        bNiv8->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(bNiv8, 3, 2, 1, 1);

        labNiv1 = new QLabel(gridLayoutWidget);
        labNiv1->setObjectName(QStringLiteral("labNiv1"));
        labNiv1->setEnabled(true);
        labNiv1->setFont(font1);
        labNiv1->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(labNiv1, 2, 0, 1, 1);

        bNiv6 = new QPushButton(gridLayoutWidget);
        bNiv6->setObjectName(QStringLiteral("bNiv6"));

        gridLayout->addWidget(bNiv6, 3, 0, 1, 1);

        bNiv7 = new QPushButton(gridLayoutWidget);
        bNiv7->setObjectName(QStringLiteral("bNiv7"));

        gridLayout->addWidget(bNiv7, 3, 1, 1, 1);

        labNiv4 = new QLabel(gridLayoutWidget);
        labNiv4->setObjectName(QStringLiteral("labNiv4"));
        labNiv4->setFont(font1);

        gridLayout->addWidget(labNiv4, 2, 3, 1, 1);

        labNiv5 = new QLabel(gridLayoutWidget);
        labNiv5->setObjectName(QStringLiteral("labNiv5"));
        labNiv5->setFont(font1);

        gridLayout->addWidget(labNiv5, 2, 4, 1, 1);

        bNiv10 = new QPushButton(gridLayoutWidget);
        bNiv10->setObjectName(QStringLiteral("bNiv10"));

        gridLayout->addWidget(bNiv10, 3, 4, 1, 1);

        bNiv4 = new QPushButton(gridLayoutWidget);
        bNiv4->setObjectName(QStringLiteral("bNiv4"));

        gridLayout->addWidget(bNiv4, 0, 3, 1, 1);

        labNiv8 = new QLabel(gridLayoutWidget);
        labNiv8->setObjectName(QStringLiteral("labNiv8"));
        labNiv8->setFont(font1);

        gridLayout->addWidget(labNiv8, 4, 2, 1, 1);

        labNiv2 = new QLabel(gridLayoutWidget);
        labNiv2->setObjectName(QStringLiteral("labNiv2"));
        labNiv2->setMinimumSize(QSize(0, 0));
        labNiv2->setFont(font1);

        gridLayout->addWidget(labNiv2, 2, 1, 1, 1);

        labNiv3 = new QLabel(gridLayoutWidget);
        labNiv3->setObjectName(QStringLiteral("labNiv3"));
        labNiv3->setFont(font1);

        gridLayout->addWidget(labNiv3, 2, 2, 1, 1);

        bNiv9 = new QPushButton(gridLayoutWidget);
        bNiv9->setObjectName(QStringLiteral("bNiv9"));

        gridLayout->addWidget(bNiv9, 3, 3, 1, 1);

        bNiv5 = new QPushButton(gridLayoutWidget);
        bNiv5->setObjectName(QStringLiteral("bNiv5"));

        gridLayout->addWidget(bNiv5, 0, 4, 1, 1);

        labNiv9 = new QLabel(gridLayoutWidget);
        labNiv9->setObjectName(QStringLiteral("labNiv9"));
        labNiv9->setFont(font1);

        gridLayout->addWidget(labNiv9, 4, 3, 1, 1);

        bNiv3 = new QPushButton(gridLayoutWidget);
        bNiv3->setObjectName(QStringLiteral("bNiv3"));

        gridLayout->addWidget(bNiv3, 0, 2, 1, 1);

        labNiv6 = new QLabel(gridLayoutWidget);
        labNiv6->setObjectName(QStringLiteral("labNiv6"));
        labNiv6->setFont(font1);

        gridLayout->addWidget(labNiv6, 4, 0, 1, 1);

        bNiv1 = new QPushButton(gridLayoutWidget);
        bNiv1->setObjectName(QStringLiteral("bNiv1"));
        bNiv1->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(bNiv1, 0, 0, 1, 1);

        labNiv10 = new QLabel(gridLayoutWidget);
        labNiv10->setObjectName(QStringLiteral("labNiv10"));
        labNiv10->setFont(font1);

        gridLayout->addWidget(labNiv10, 4, 4, 1, 1);

        bNiv2 = new QPushButton(gridLayoutWidget);
        bNiv2->setObjectName(QStringLiteral("bNiv2"));

        gridLayout->addWidget(bNiv2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1070, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        titreJeu->setText(QApplication::translate("MainWindow", "SOKOBAN", Q_NULLPTR));
        labNiv7->setText(QString());
        bNiv8->setText(QApplication::translate("MainWindow", "Niveau 8", Q_NULLPTR));
        labNiv1->setText(QString());
        bNiv6->setText(QApplication::translate("MainWindow", "Niveau 6", Q_NULLPTR));
        bNiv7->setText(QApplication::translate("MainWindow", "Niveau 7", Q_NULLPTR));
        labNiv4->setText(QString());
        labNiv5->setText(QString());
        bNiv10->setText(QApplication::translate("MainWindow", "Niveau 10", Q_NULLPTR));
        bNiv4->setText(QApplication::translate("MainWindow", "Niveau 4", Q_NULLPTR));
        labNiv8->setText(QString());
        labNiv2->setText(QString());
        labNiv3->setText(QString());
        bNiv9->setText(QApplication::translate("MainWindow", "Niveau 9", Q_NULLPTR));
        bNiv5->setText(QApplication::translate("MainWindow", "Niveau 5", Q_NULLPTR));
        labNiv9->setText(QString());
        bNiv3->setText(QApplication::translate("MainWindow", "Niveau 3", Q_NULLPTR));
        labNiv6->setText(QString());
        bNiv1->setText(QApplication::translate("MainWindow", "Niveau 1", Q_NULLPTR));
        labNiv10->setText(QString());
        bNiv2->setText(QApplication::translate("MainWindow", "Niveau 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
