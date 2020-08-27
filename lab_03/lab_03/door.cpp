#include "door.h"

Door::Door(QObject *parent) : QObject(parent)
{
    this->status = CLOSED;
    this->time = 700;

    connect(&timeOpen, SIGNAL(timeout()), this, SLOT(open()));
    connect(&timeClose, SIGNAL(timeout()), this, SLOT(close()));
    connect(&timeWait,SIGNAL(timeout()), this, SLOT(startClosing()));
}

void Door::open()
{
    if (status == OPENING)
    {
        this->status = OPENED;
        info = "Двери открыты";
        emit newInfo(info);
        timeWait.setSingleShot(true);
        timeWait.start(time);
    }
}

void Door::close()
{
    if (status == CLOSING)
    {
        this->status = CLOSED;

        info = "Двери закрылись";
        emit newInfo(info);
    }
    emit closed();
}

void Door::startOpening()
{
    if (status == CLOSED)
    {
        this->status = OPENING;
        info = "Двери открываются";
        emit newInfo(info);
        timeOpen.setSingleShot(true);
        timeOpen.start(time);
    }
}

void Door::startClosing()
{
    if (status == OPENED)
    {
        this->status = CLOSING;
        info = "Двери закрываются";
        emit newInfo(info);
        timeClose.setSingleShot(true);
        timeClose.start(time);
    }
    else if (status == CLOSED)
    {
        emit closed();
    }
}
