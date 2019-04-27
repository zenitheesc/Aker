#include "mde.h"
#include "ui_mde.h"
#include "addfunc.h"
#include <QtDebug>

MDE::MDE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MDE)
{
    ui->setupUi(this);
}

MDE::~MDE()
{
    delete ui;
}

void MDE::on_pbAddFunction_clicked()
{
    hide(); //To hide the main window
    function = new addFunc(this);
    function->show();
}

void MDE::on_pbExit_clicked()
{
    parentWidget()->show();
    this->close();

}
