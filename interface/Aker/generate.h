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
    explicit generate(QWidget *parent = 0);
    ~generate();

private:
    Ui::generate *ui;
};

#endif // GENERATE_H
