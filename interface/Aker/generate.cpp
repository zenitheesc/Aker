#include "generate.h"
#include "ui_generate.h"
#include "codegenerator.h"

generate::generate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::generate)
{
    CodeGenerator code_gen;

    //Just initializing the modules_ids arrays with the number of modules
    this->modules_ids = (int *)malloc(this->number_of_modules * sizeof(int));

    ui->setupUi(this);

    // Main Module
    this->modules_names_main = (char **)malloc(100 * sizeof(char*));
    for(int i = 0; i < 100; i++){
        this->modules_names_main[i] = (char *)malloc(100 * sizeof(char));
    }

    this->modules_names_main = code_gen.get_all_modules_names_by_classifier("Main Module");

    for(int j = 0; j < 100; j++){
        //Verify if the module name starts within 'a' and 'z'
        if(this->modules_names_main[j][0] > 97 && this->modules_names_main[j][0] < 122){
            ui->listMain->addItem(this->modules_names_main[j]);
        }

    }

    //Comm Module
    this->modules_names_comm = (char **)malloc(100 * sizeof(char*));
    for(int i = 0; i < 100; i++){
        this->modules_names_comm[i] = (char *)malloc(100 * sizeof(char));
    }

    this->modules_names_comm = code_gen.get_all_modules_names_by_classifier("Comm Module");

    for(int j = 0; j < 100; j++){
        if(this->modules_names_comm[j][0] > 97 && this->modules_names_comm[j][0] < 122){
            ui->listComm->addItem(this->modules_names_comm[j]);
        }
    }

    //Sensor Module
    this->modules_names_sensor = (char **)malloc(100 * sizeof(char*));
    for(int i = 0; i < 100; i++){
        this->modules_names_sensor[i] = (char *)malloc(100 * sizeof(char));
    }

    this->modules_names_sensor = code_gen.get_all_modules_names_by_classifier("Sensor Module");

    for(int j = 0; j < 100; j++){
        if(this->modules_names_sensor[j][0] > 97 && this->modules_names_sensor[j][0] < 122){
            ui->listSensor->addItem(this->modules_names_sensor[j]);
        }
    }
}

generate::~generate()
{
    delete ui;
}


void generate::on_listMainPb_clicked()
{
    CodeGenerator code_gen;

    // Main Functions
    this->functions_names_main = (char **)malloc(100 * sizeof(char*));
    for(int i = 0; i < 100; i++){
        this->functions_names_main[i] = (char *)malloc(100 * sizeof(char));
    }

    QString moduleNameQString;
    string moduleNameCString;

    // If the user didn't selected anything
    if(ui->listMain->selectedItems().size() == 0){
        ui->listMain->setCurrentItem(ui->listMain->itemAt(0,0));
    }

    moduleNameQString = ui->listMain->currentItem()->text();
    moduleNameCString = moduleNameQString.toStdString();
    this->functions_names_main = code_gen.get_all_functions_of_a_module(const_cast<char*>(moduleNameCString.c_str()));

    this->modules_ids[0] = code_gen.get_module_id_by_name(const_cast<char*>(moduleNameCString.c_str()));

    for(int j = 0; j < 100; j++){
        if(this->functions_names_main[j][0] > 97 && this->functions_names_main[j][0] < 122){
            ui->listMainFunctions->addItem(this->functions_names_main[j]);
        }
    }

}

void generate::on_listCommPb_clicked()
{
    CodeGenerator code_gen;

    // Comm Functions
    this->functions_names_comm = (char **)malloc(100 * sizeof(char*));
    for(int i = 0; i < 100; i++){
        this->functions_names_comm[i] = (char *)malloc(100 * sizeof(char));
    }

    QString moduleNameQString;
    string moduleNameCString;

    // If the user didn't selected anything
    if(ui->listComm->selectedItems().size() == 0){
        ui->listComm->setCurrentItem(ui->listComm->itemAt(0,0));
    }

    moduleNameQString = ui->listComm->currentItem()->text();
    moduleNameCString = moduleNameQString.toStdString();
    this->functions_names_comm = code_gen.get_all_functions_of_a_module(const_cast<char*>(moduleNameCString.c_str()));

    this->modules_ids[1] = code_gen.get_module_id_by_name(const_cast<char*>(moduleNameCString.c_str()));

    for(int j = 0; j < 100; j++){
        if(this->functions_names_comm[j][0] > 97 && this->functions_names_comm[j][0] < 122){
            ui->listCommFunctions->addItem(this->functions_names_comm[j]);
        }
    }

}

void generate::on_listSensorPb_clicked()
{
    CodeGenerator code_gen;

    // Sensor Functions
    this->functions_names_sensor = (char **)malloc(100 * sizeof(char*));
    for(int i = 0; i < 100; i++){
        this->functions_names_sensor[i] = (char *)malloc(100 * sizeof(char));
    }

    QString moduleNameQString;
    string moduleNameCString;

    // If the user didn't selected anything
    if(ui->listSensor->selectedItems().size() == 0){
        ui->listSensor->setCurrentItem(ui->listSensor->itemAt(0,0));
    }

    moduleNameQString = ui->listSensor->currentItem()->text();
    moduleNameCString = moduleNameQString.toStdString();
    this->functions_names_sensor = code_gen.get_all_functions_of_a_module(const_cast<char*>(moduleNameCString.c_str()));

    this->modules_ids[2] = code_gen.get_module_id_by_name(const_cast<char*>(moduleNameCString.c_str()));

    for(int j = 0; j < 100; j++){
        if(this->functions_names_sensor[j][0] > 97 && this->functions_names_sensor[j][0] < 122){
            ui->listSensorFunctions->addItem(this->functions_names_sensor[j]);
        }
    }

}

void generate::on_mainFunctionPb_clicked()
{
    QString functionToAddQString;
    string functionToAddCString;

    //If nothing selected, uses the first item
    if(ui->listMainFunctions->selectedItems().size() == 0){
        ui->listMainFunctions->setCurrentItem(ui->listMainFunctions->itemAt(0,0));
    }

    functionToAddQString = ui->listMainFunctions->currentItem()->text();
    functionToAddCString = functionToAddQString.toStdString();
    ui->listCurStateFunction->addItem(const_cast<char*>(functionToAddCString.c_str()));
}

void generate::on_commFunctionPb_clicked()
{
    QString functionToAddQString;
    string functionToAddCString;

    //If nothing selected, uses the first item
    if(ui->listCommFunctions->selectedItems().size() == 0){
        ui->listCommFunctions->setCurrentItem(ui->listCommFunctions->itemAt(0,0));
    }

    functionToAddQString = ui->listCommFunctions->currentItem()->text();
    functionToAddCString = functionToAddQString.toStdString();
    ui->listCurStateFunction->addItem(const_cast<char*>(functionToAddCString.c_str()));
}

void generate::on_sensorFunctionPb_clicked()
{
    QString functionToAddQString;
    string functionToAddCString;

    //If nothing selected, uses the first item
    if(ui->listSensorFunctions->selectedItems().size() == 0){
        ui->listSensorFunctions->setCurrentItem(ui->listSensorFunctions->itemAt(0,0));
    }

    functionToAddQString = ui->listSensorFunctions->currentItem()->text();
    functionToAddCString = functionToAddQString.toStdString();
    ui->listCurStateFunction->addItem(const_cast<char*>(functionToAddCString.c_str()));
}

void generate::on_numberOfStatesPb_clicked()
{
    this->number_of_states = ui->vNumberOfStates->text().toInt();

    for(int i = 0; i < this->number_of_states; i++){
        ui->curStateBox->addItem(QString::number(i));
    }

    this->states_functions = (int **)malloc(this->number_of_states * sizeof(int*));

    this->functions_per_state = (int *)malloc(this->number_of_states * sizeof(int));

}

void generate::on_confirmFunctionsForStatePb_clicked()
{
    CodeGenerator code_gem;

    int curr_state_index;
    QString currentTextBox;
    currentTextBox = ui->curStateBox->currentText();
    curr_state_index = currentTextBox.toInt();

    this->states_functions[curr_state_index] = (int *)malloc(ui->listCurStateFunction->count() * sizeof(int));

    this->functions_per_state[curr_state_index] = ui->listCurStateFunction->count();

    for(int i = 0; i < ui->listCurStateFunction->count(); i++)
    {
        QListWidgetItem* functionItem = ui->listCurStateFunction->item(i);
        QString functionNameAsQString = functionItem->text();
        string functionNameAsCString = functionNameAsQString.toStdString();
        int id = code_gem.get_function_id_by_name(const_cast<char*>(functionNameAsCString.c_str()));
        this->states_functions[curr_state_index][i] = id;
    }

    int nextStateNumber = currentTextBox.toInt() + 1;
    ui->curStateBox->setCurrentIndex(nextStateNumber);

}

void generate::on_clearCurrFunctionStatePb_clicked()
{
    ui->listCurStateFunction->clear();
}

void generate::on_generatePb_clicked()
{
    CodeGenerator code_gen;

    code_gen.ui_generate(this->modules_chosen, this->modules_ids, this->functions_per_state, this->number_of_states, this->states_functions);

    parentWidget()->show();
    this->hide();
}



void generate::on_numberOfModulesPb_clicked()
{
    this->modules_chosen = ui->vNumberOfModules->text().toInt();
}
