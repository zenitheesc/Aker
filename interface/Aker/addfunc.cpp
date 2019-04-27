#include "addfunc.h"
#include "ui_addfunc.h"

addFunc::addFunc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addFunc)
{
    ui->setupUi(this);
}

addFunc::~addFunc()
{
    delete ui;
}

int addFunc::getPar()
{
    return this->Par;
}

void addFunc::on_pbOk_clicked()
{
    this->Par = ui->vFuncParameters->text().toInt();

    for(int i = 0; i<this->Par; i++){
        param = new eachParam(this);
        param->show();

    }
    //parentWidget()->show();
    //this->hide();
}
