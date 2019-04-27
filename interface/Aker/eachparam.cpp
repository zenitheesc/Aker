#include "eachparam.h"
#include "ui_eachparam.h"

eachParam::eachParam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eachParam)
{
    ui->setupUi(this);
}

eachParam::~eachParam()
{
    delete ui;
}
