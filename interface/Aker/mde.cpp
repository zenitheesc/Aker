#include "mde.h"
#include "ui_mde.h"
#include <QPixmap>
MDE::MDE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MDE)
{
    ui->setupUi(this);
    QPixmap zenithLogo(":/resources/Images/Logo.png");
    int logoW = ui->zenithLogo->width();
    int logoH = ui->zenithLogo->height();
    ui->zenithLogo->setPixmap(zenithLogo.scaled(logoW,logoH,Qt::KeepAspectRatio));

}

MDE::~MDE()
{
    delete ui;
}

void MDE::on_pushButton_clicked()
{

}
