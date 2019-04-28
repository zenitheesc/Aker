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


char* addModule::get_module_classifier(){
    return this->module_classifier;
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

    QString moduleClassifierQString;
    string moduleClassifierCString;
    moduleClassifierQString = ui->vModuleClassifier->text();
    moduleClassifierCString = moduleClassifierQString.toStdString();
    this->module_classifier = const_cast<char*>(moduleClassifierCString.c_str());

    code_gen.ui_new_module(this->module_id, this->module_name, this->module_classifier);

    parentWidget()->show();
    this->hide();
}
