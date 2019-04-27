#include "addmodule.h"
#include "ui_addmodule.h"

addModule::addModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addModule)
{
    ui->setupUi(this);
}

addModule::~addModule()
{
    delete ui;
}
