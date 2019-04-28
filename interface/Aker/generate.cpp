#include "generate.h"
#include "ui_generate.h"

generate::generate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::generate)
{
    ui->setupUi(this);
}

generate::~generate()
{
    delete ui;
}
