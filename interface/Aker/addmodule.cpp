#include "addmodule.h"
#include "ui_addmodule.h"
#include "codegenerator.h"

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

int addModule::get_module_id(){
    return this->module_id;
}

char* addModule::get_module_name(){
    return this->module_name;
}



void addModule::on_pbOk_clicked()
{
    CodeGenerator code_gen;

    this->module_id = ui->vModuleID->text().toInt();

    QString moduleNameQString;
    string moduleNameCString;
    moduleNameQString = ui->vModuleName->text();
    moduleNameCString = moduleNameQString.toStdString();
    this->module_name = const_cast<char*>(moduleNameCString.c_str());

    code_gen.ui_new_module(this->module_id, this->module_name);

    parentWidget()->show();
    this->hide();
}
