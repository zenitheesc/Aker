#ifndef MDE_H
#define MDE_H

#include <QMainWindow>
#include <addfunc.h>

namespace Ui {
class MDE;
}

class MDE : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDE(QWidget *parent = nullptr);

    addFunc *function;

    ~MDE();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pbAddFunction_clicked();

    void on_pbExit_clicked();

private:
    Ui::MDE *ui;
};

#endif // MDE_H
