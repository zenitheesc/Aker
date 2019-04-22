#include "firstmenu.h"
#include "ui_firstmenu.h"
#include <QPixmap>


FirstMenu::FirstMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstMenu)
{
    ui->setupUi(this);
    QPixmap zenithLogo(":/resources/Images/Logo.png");
    int logoW = ui->ZenithLogo->width();
    int logoH = ui->ZenithLogo->height();
    ui->ZenithLogo->setPixmap(zenithLogo.scaled(3*logoW,3*logoH,Qt::KeepAspectRatio));
}

FirstMenu::~FirstMenu()
{
    delete ui;
}

void FirstMenu::on_startMDE_clicked()
{
    hide(); //Para esconder a janela principal;
    mdeWindow = new MDE(this);
    mdeWindow->show();
}

void FirstMenu::on_startMM_clicked()
{
    hide(); //Para esconder a janela principal;
    mmWindow = new MM(this);
    mmWindow->show();
}


void FirstMenu::on_startMA_clicked()
{
    hide(); //Para esconder a janela principal;
    maWindow = new MA(this);
    maWindow->show();
}
