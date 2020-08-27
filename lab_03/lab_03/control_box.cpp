#include "control_box.h"

ControlBox::ControlBox(QWidget *parent) : QWidget(parent)
{
    this->direction = 0;
    this->maxFloor = 4;
    this->minFloor = 1;
    this->curFloor = this->minFloor;
    this->status = NO_TARGET;

    for (int i = minFloor; i <= maxFloor; i++)
    {
        targets[i - 1] = false;
    }
}

void ControlBox::addTarget(int floor)
{
    status = HAS_TARGET;
    this->targets[floor - 1] = true;
    getNewTarget(floor);
    emit newTarget(floor);
}

void ControlBox::removeTarget(int i)
{
    this->targets[i - 1] = false;
    if (getNewTarget(i))
    {
        emit newTarget(i);
    }
    else
    {
        status = NO_TARGET;
    }
}

void ControlBox::setDirection(int dir)
{
    this->direction = dir;
}

void ControlBox::setTarget(int i)
{
    this->target = i;
}

int ControlBox::getTarget()
{
    return this->target;
}

int ControlBox::getDirection()
{
    return this->direction;
}

int ControlBox::getCurTarg()
{
    return this->curFloor;
}

void ControlBox::setCurTarg(int floor)
{
    this->curFloor = floor;
}

bool ControlBox::getNewTarget(int &target)
{
    int h;
    if (direction == 0)
    {
        h = -1;
    }
    else
    {
        h = direction;
    }

    for(int i = curFloor; i <= maxFloor && i >= minFloor; i += h)
    {
        if(targets[i - 1])
        {
            target = i;
            return true;
        }
    }

    h *= -1;
    for(int i = curFloor; i <= maxFloor && i >= minFloor; i += h)
    {
        if(targets[i - 1])
        {

            target = i;
            return true;
        }
    }
    target = this->curFloor;
    return false;
}
