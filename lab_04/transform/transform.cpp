#include "transform.h"

void Mover::transform(Object* obj)
{
    if (obj->visible())
    {
        Model* model = (Model*)(obj);
        std::vector<Point3D> points = model->getPoints();
        for (size_t i = 0; i < points.size(); i++)
        {
            points[i].move(this->firstParam(), this->secondParam(), this->thirdParam());
        }
        model->setPoints(points);
    }
}

void Scaler::transform(Object* obj)
{
    if (obj->visible())
    {
        Model* model = (Model*)(obj);
        std::vector<Point3D> points = model->getPoints();
        for (size_t i = 0; i < points.size(); i++)
        {
            points[i].scale(this->firstParam(), this->secondParam(), this->thirdParam());
        }
        model->setPoints(points);
    }
}

void Rotater::transform(Object* obj)
{
    if (obj->visible())
    {
        Model* model = (Model*)(obj);
        std::vector<Point3D> points = model->getPoints();
        for (size_t i = 0; i < points.size(); i++)
        {
            points[i].rotate(this->firstParam(), this->secondParam(), this->thirdParam());
        }
        model->setPoints(points);
    }
}
