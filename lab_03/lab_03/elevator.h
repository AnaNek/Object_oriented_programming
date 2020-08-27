#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <deque>
#include <algorithm>
#include <QQueue>
#include <QDebug>
#include <QTimer>
#include "door.h"
#include "timer.h"
#include "control_box.h"

class Elevator : public QObject
{
    Q_OBJECT

    enum elevatorStatus
    {
        MOVING,
        STOPPED,
        TARGET_RECEIVED
    };

public:
    Elevator(QObject *parent = 0);
    Door* getDoors();
    ControlBox* getControlBox();
    int getCurFloor();

private:
    elevatorStatus status;
    Door doors;
    ControlBox control;

    QTimer timeMove;
    int time;

    QString info;

    int curFloor;
    int direction;
    int target;

signals:
    void targetIsAchieved();
    void newInfo(QString);

    void move();
    void stoped(int);

public slots:
    void moving();
    void stop();
    void onTargetReceived(int);
};

#endif
