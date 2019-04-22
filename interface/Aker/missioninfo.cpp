#include "missioninfo.h"
#include "ui_missioninfo.h"

MissionInfo::MissionInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MissionInfo)
{
    ui->setupUi(this);
}

MissionInfo::~MissionInfo()
{
    delete ui;
}
