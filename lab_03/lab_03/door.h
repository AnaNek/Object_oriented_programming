#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "timer.h"

class Door : public QObject
{
    Q_OBJECT
    enum doorStatus
    {
        OPENED,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    explicit Door(QObject *parent = 0);

private:
    doorStatus status;
    QTimer timeOpen;
    QTimer timeClose;
    QTimer timeWait;

    int time;
    QString info;

signals:
    void closed();
    void newInfo(QString);

public slots:
    void startOpening();
    void startClosing();

private slots:
    void open();
    void close();
};

#endif
