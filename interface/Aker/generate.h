#ifndef GENERATE_H
#define GENERATE_H

#include <QMainWindow>

namespace Ui {
class generate;
}

class generate : public QMainWindow
{
    Q_OBJECT

public:
    explicit generate(QWidget *parent = nullptr);
    ~generate();

    char ** modules_names_main;
    char ** modules_names_comm;
    char ** modules_names_sensor;
    int curr_state;
    char ** functions_names_main;
    char ** functions_names_comm;
    char ** functions_names_sensor;
    int number_of_states;
    int ** states_functions;
    int number_of_modules;
    int * modules_ids;
    int number_of_functions_this_state;
    int * functions_per_state;

    //TODO getters
private slots:

    void on_listMainPb_clicked();

    void on_listCommPb_clicked();

    void on_listSensorPb_clicked();

    void on_mainFunctionPb_clicked();

    void on_commFunctionPb_clicked();

    void on_sensorFunctionPb_clicked();

    void on_numberOfStatesPb_clicked();

    void on_confirmFunctionsForStatePb_clicked();

    void on_clearCurrFunctionStatePb_clicked();

    void on_generatePb_clicked();



    void on_numberOfModulesPb_clicked();

private:
    Ui::generate *ui;
};

#endif // GENERATE_H
