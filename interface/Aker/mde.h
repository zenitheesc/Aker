#ifndef MDE_H
#define MDE_H

#include <QMainWindow>

namespace Ui {
class MDE;
}

class MDE : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDE(QWidget *parent = nullptr);
    ~MDE();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MDE *ui;
};

#endif // MDE_H
