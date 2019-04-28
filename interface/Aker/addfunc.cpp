#include "addfunc.h"
#include "ui_addfunc.h"
#include "codegenerator.h"
#include "qdebug.h"

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

int addFunc::get_function_id(){
    return this->function_id;
}

char* addFunc::get_function_name(){
    return this->function_name;
}

char* addFunc::get_return_type(){
    return this->return_type;
}

int addFunc::get_number_of_parameters(){
    return this->number_of_parameters;
}

char** addFunc::get_param_types_list(){
    char** param_types_list = (char **) malloc((sizeof(this->param_types_list)/sizeof(this->param_types_list[0])) *
                                                    sizeof(char *));
    for(int i = 0; i < (sizeof(this->param_types_list)/sizeof(this->param_types_list)); i++){
        param_types_list[i] = this->param_types_list[i];
    }
    return param_types_list;
}

char** addFunc::get_param_names_list(){
    char** param_names_list = (char **) malloc((sizeof(this->param_names_list)/sizeof(this->param_names_list[0])) *
                                                    sizeof(char *));
    for(int i = 0; i < (sizeof(this->param_names_list)/sizeof(this->param_names_list)); i++){
        param_names_list[i] = this->param_names_list[i];
    }
    return param_names_list;
}

char* addFunc::get_module_of_function(){
    return this->module_of_function;
}

void addFunc::on_pbOk_clicked()
{
    CodeGenerator code_gen;

    this->function_id = ui->vFuncID->text().toInt();

    QString funcNameQString;
    string funcNameCString;
    funcNameQString = ui->vFuncName->text();
    funcNameCString = funcNameQString.toStdString();
    this->function_name = const_cast<char*>(funcNameCString.c_str());

    QString funcModuleOfFunctionQString;
    string funcModuleOfFunctionCString;
    funcModuleOfFunctionQString = ui->vModuleOfFunction->text();
    funcModuleOfFunctionCString = funcModuleOfFunctionQString.toStdString();
    this->module_of_function = const_cast<char*>(funcModuleOfFunctionCString.c_str());

    QString funcRetTypeQString;
    string funcRetTypeCString;
    funcRetTypeQString = ui->vFuncRetType->text();
    funcRetTypeCString = funcRetTypeQString.toStdString();
    this->return_type = const_cast<char*>(funcRetTypeCString.c_str());

    this->number_of_parameters = ui->vFuncParameters->text().toInt();

    string paramTypesAsCString[10];
    string paramNamesAsCString[10];
    QString vParamTypes[10];
    QString vParamNames[10];

    vParamTypes[0] = ui->vParamType0->text();
    vParamTypes[1] = ui->vParamType1->text();
    vParamTypes[2] = ui->vParamType2->text();
    vParamTypes[3] = ui->vParamType3->text();
    vParamTypes[4] = ui->vParamType4->text();
    vParamTypes[5] = ui->vParamType5->text();
    vParamTypes[6] = ui->vParamType6->text();
    vParamTypes[7] = ui->vParamType7->text();
    vParamTypes[8] = ui->vParamType8->text();
    vParamTypes[9] = ui->vParamType9->text();

    vParamNames[0] = ui->vParamName0->text();
    vParamNames[1] = ui->vParamName1->text();
    vParamNames[2] = ui->vParamName2->text();
    vParamNames[3] = ui->vParamName3->text();
    vParamNames[4] = ui->vParamName4->text();
    vParamNames[5] = ui->vParamName5->text();
    vParamNames[6] = ui->vParamName6->text();
    vParamNames[7] = ui->vParamName7->text();
    vParamNames[8] = ui->vParamName8->text();
    vParamNames[9] = ui->vParamName9->text();

    int i = 0;
    this->param_types_list = (char **)malloc(10 * sizeof(char*));
    this->param_names_list = (char **)malloc(10 * sizeof(char*));

    for(i = 0; i < this->number_of_parameters; i++){
        this->param_types_list[i] = (char *)malloc(100 * sizeof(char));
        paramTypesAsCString[i] = vParamTypes[i].toStdString();
        this->param_types_list[i] = const_cast<char*>(paramTypesAsCString[i].c_str());

        this->param_names_list[i] = (char *)malloc(100 * sizeof(char));
        paramNamesAsCString[i] = vParamNames[i].toStdString();
        this->param_names_list[i] = const_cast<char*>(paramNamesAsCString[i].c_str());
    }

    code_gen.ui_new_function(this->function_id, this->function_name, this->module_of_function,
                             this->return_type, this->number_of_parameters,
                             this->param_types_list, this->param_names_list);

    parentWidget()->show();
    this->hide();
}
