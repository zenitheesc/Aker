#include "ma.h"
#include "ui_ma.h"

MA::MA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MA)
{
    ui->setupUi(this);
}

MA::~MA()
{
    delete ui;
}
