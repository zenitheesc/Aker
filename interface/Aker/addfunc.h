#ifndef ADDFUNC_H
#define ADDFUNC_H

#include <QMainWindow>
#include <eachparam.h>

namespace Ui {
class addFunc;
}

class addFunc : public QMainWindow
{
    Q_OBJECT

public:
    explicit addFunc(QWidget *parent = nullptr);
    ~addFunc();

    int Par = 0;

    int getPar();

    QString param_types[10];
    QString param_names[10];


private slots:
    void on_pushButton_clicked();

    void on_pbOk_clicked();

private:
    Ui::addFunc *ui;
};

#endif // ADDFUNC_H
