#include "firstmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstMenu w;
    w.show();

    return a.exec();
}
