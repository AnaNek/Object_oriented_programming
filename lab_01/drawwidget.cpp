#include "drawwidget.h"

void DrawWidget::setPaintingFlag(bool value)
{
    flag = value;
}

void DrawWidget::setPoints(Point *points, int n)
{
    if (this->points)
        delete [] this->points;

    this->numPoints = n;

    this->points = new Point[n];

    for (int i = 0; i < n; i++)
    {
        this->points[i] = points[i];
    }
}

void DrawWidget::setInd(Indexes *ind, int n)
{
    if (this->ind)
        delete [] this->ind;

    this->numInd = n;

    this->ind = new Indexes[n];

    for (int i = 0; i < n; i++)
    {
        this->ind[i] = ind[i];
    }
}

void DrawWidget::draw()
{
    QPainter painter(this);

    painter.fillRect(0, 0, this->width(), this->height(), Qt::white);

    painter.setPen(QPen(Qt::black, 1));

    if (!flag)
    {
        return;
    }

    for (int i = 0; i < numInd / 2; i++)
    {
        int first = ind[i].first_index;
        int second = ind[i].second_index;

        Point p1 = points[first];
        Point p2 = points[second];

        QPointF pf1 = QPointF(500 * p1.x + this->width() / 2, -500 * p1.y + this->height() / 2);
        QPointF pf2 = QPointF(500 * p2.x + this->width() / 2, -500 * p2.y + this->height() / 2);

        painter.drawLine(pf1, pf2);
    }
}

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    flag = false;
    this->ind = nullptr;
    this->points = nullptr;
}

DrawWidget::~DrawWidget()
{
    if (this->ind)
        delete[] ind;

    if (this->points)
        delete[] this->points;
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    draw();
}
