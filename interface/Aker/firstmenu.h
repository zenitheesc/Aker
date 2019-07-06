#ifndef FIRSTMENU_H
#define FIRSTMENU_H

#include <QMainWindow>
#include "mde.h"
#include "mm.h"
#include "ma.h"

namespace Ui {
class FirstMenu;
}

class FirstMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstMenu(QWidget *parent = nullptr);
    ~FirstMenu();

private slots:
    void on_startMDE_clicked();
    void on_startMM_clicked();
    void on_startMA_clicked();

private:
    Ui::FirstMenu *ui;
    MDE *mdeWindow;
    MM  *mmWindow;
    MA  *maWindow;
};

#endif // FIRSTMENU_H
