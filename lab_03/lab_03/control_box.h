#ifndef CONTROL_BOX_H
#define CONTROL_BOX_H

#include <QObject>
#include <QWidget>
#include <QDebug>

#define FLOORNUM 4

class ControlBox : public QWidget
{
    Q_OBJECT
    enum Status
    {
        HAS_TARGET,
        NO_TARGET
    };

public:
    ControlBox(QWidget *parent = 0);
    int getTarget();
    int getDirection();
    void setDirection(int);
    void setTarget(int);
    int getCurTarg();
    void setCurTarg(int);
    bool getNewTarget(int&);

public slots:
    void removeTarget(int);
    void addTarget(int);

signals:
    void newTarget(int);

private:
    bool targets[FLOORNUM];
    int maxFloor;
    int minFloor;
    int curFloor;
    int direction;
    int target;
    Status status;
};

#endif
