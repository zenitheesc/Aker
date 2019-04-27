#ifndef EACHPARAM_H
#define EACHPARAM_H

#include <QMainWindow>

namespace Ui {
class eachParam;
}

class eachParam : public QMainWindow
{
    Q_OBJECT

public:
    explicit eachParam(QWidget *parent = nullptr);
    ~eachParam();

private:
    Ui::eachParam *ui;
};

#endif // EACHPARAM_H
