#ifndef ADDMODULE_H
#define ADDMODULE_H

#include <QMainWindow>

namespace Ui {
class addModule;
}

class addModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit addModule(QWidget *parent = nullptr);
    ~addModule();

    int module_id;
    char* module_name;
    char* module_classifier;

    int get_module_id();
    char* get_module_name();
    char* get_module_classifier();

private slots:
    void on_pbOk_clicked();

private:
    Ui::addModule *ui;
};

#endif // ADDMODULE_H
