#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <math.h>
#include "repository.h"

class DrawWidget : public QWidget
{
    Q_OBJECT

private:
    bool flag;
    Point *points;
    int numPoints;
    Indexes *ind;
    int numInd;

public:
    void draw();
    void setPaintingFlag(bool value);
    void setPoints(Point *points, int n);
    void setInd(Indexes *ind, int n);
    explicit DrawWidget(QWidget *parent = nullptr);
    ~DrawWidget();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // DRAWWIDGET_H
