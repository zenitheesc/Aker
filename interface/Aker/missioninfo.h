#ifndef MISSIONINFO_H
#define MISSIONINFO_H

#include <QMainWindow>

namespace Ui {
class MissionInfo;
}

class MissionInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MissionInfo(QWidget *parent = 0);
    ~MissionInfo();

private:
    Ui::MissionInfo *ui;
};

#endif // MISSIONINFO_H
