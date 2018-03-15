#ifndef CONFIGNIVEAU_H
#define CONFIGNIVEAU_H

#include <QDialog>

namespace Ui {
class ConfigNiveau;
}

class ConfigNiveau : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigNiveau(QWidget *parent = 0);
    ~ConfigNiveau();
    void changerPersonnage();
    void changerDecor();
    int getPerso();
    int getDecor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfigNiveau *ui;

    int m_numDecor;
    int m_numPerso;
};

#endif // CONFIGNIVEAU_H
