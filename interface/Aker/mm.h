#ifndef MM_H
#define MM_H

#include <QMainWindow>

namespace Ui {
class MM;
}

class MM : public QMainWindow
{
    Q_OBJECT

public:
    explicit MM(QWidget *parent = nullptr);
    ~MM();

private:
    Ui::MM *ui;
};

#endif // MM_H
