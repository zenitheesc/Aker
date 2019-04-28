#ifndef ADDFUNC_H
#define ADDFUNC_H

#include <QMainWindow>

namespace Ui {
class addFunc;
}

class addFunc : public QMainWindow
{
    Q_OBJECT

public:
    explicit addFunc(QWidget *parent = nullptr);
    ~addFunc();

    int function_id;
    char *function_name;
    char *return_type;
    int number_of_parameters;
    char **param_types_list;
    char **param_names_list;
    char *module_of_function;

    int get_function_id();
    char* get_function_name();
    char* get_return_type();
    int get_number_of_parameters();
    char** get_param_types_list();
    char** get_param_names_list();
    char* get_module_of_function();

private slots:
    void on_pbOk_clicked();

private:
    Ui::addFunc *ui;
};

#endif // ADDFUNC_H
