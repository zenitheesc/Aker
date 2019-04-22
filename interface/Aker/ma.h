#ifndef MA_H
#define MA_H

#include <QMainWindow>

namespace Ui {
class MA;
}

class MA : public QMainWindow
{
    Q_OBJECT

public:
    explicit MA(QWidget *parent = nullptr);
    ~MA();

private:
    Ui::MA *ui;
};

#endif // MA_H
