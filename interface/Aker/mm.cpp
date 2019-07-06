#include "mm.h"
#include "ui_mm.h"

MM::MM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MM)
{
    ui->setupUi(this);
}

MM::~MM()
{
    delete ui;
}
