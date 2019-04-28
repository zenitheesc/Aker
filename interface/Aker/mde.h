#ifndef MDE_H
#define MDE_H

#include <QMainWindow>
#include <addfunc.h>
#include <addmodule.h>
#include <generate.h>

namespace Ui {
class MDE;
}

class MDE : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDE(QWidget *parent = nullptr);

    addFunc *function;
    addModule *module;
    generate *startGenerate;
    ~MDE();

private slots:

    void on_pbAddFunction_clicked();

    void on_pbExit_clicked();

    void on_pbAddModule_clicked();

    void on_pbGenerate_clicked();

private:
    Ui::MDE *ui;
};

#endif // MDE_H
