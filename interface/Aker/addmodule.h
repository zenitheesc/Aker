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
    explicit addModule(QWidget *parent = 0);
    ~addModule();

private:
    Ui::addModule *ui;
};

#endif // ADDMODULE_H
