#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    this->status = STOPPED;
    this->curFloor = 1;
    this->target = 1;
    this->direction = 0;
    this->time = 700;

    timeMove.setSingleShot(true);

    connect(this, SIGNAL(targetIsAchieved()), this, SLOT(stop()));
    connect(&timeMove, SIGNAL(timeout()), this, SLOT(moving()));
    connect(this, SIGNAL(move()), &doors, SLOT(startClosing()));
    connect(&doors, SIGNAL(closed()), this, SLOT(moving()));
    connect(this, SIGNAL(stoped(int)), &control, SLOT(removeTarget(int)));
    connect(this, SIGNAL(stoped(int)), &doors, SLOT(startOpening()));
    connect(&control, SIGNAL(newTarget(int)), this, SLOT(onTargetReceived(int)));
}

void Elevator::onTargetReceived(int i)
{
    if (status == MOVING)
    {
        return;
    }

    status = TARGET_RECEIVED;

    target = i;

    if (target > curFloor)
    {
        direction = 1;
        emit move();
        return;
    }
    else if (target < curFloor)
    {
        direction = -1;
        emit move();
        return;
    }
    else if (target == curFloor)
    {
        emit targetIsAchieved();
    }
}

void Elevator::moving()
{
    if (status == STOPPED)
        return;

    if(status == MOVING)
    {
        info = "Лифт на " + QString::number(curFloor) + " этаже";
        emit newInfo(info);

        curFloor += direction;
    }
    status = MOVING;
    if(target == curFloor)
    {
        emit targetIsAchieved();
    }
    else
    {
        timeMove.start(time);
    }
}

void Elevator::stop()
{
    status = STOPPED;

    info = "Лифт стоит на " + QString::number(curFloor) + " этаже";
    emit newInfo(info);

    direction = 0;
    control.setDirection(direction);

    emit stoped(curFloor);
}

Door* Elevator::getDoors()
{
    return &doors;
}

ControlBox* Elevator::getControlBox()
{
    return &control;
}

int Elevator::getCurFloor()
{
    return this->curFloor;
}

