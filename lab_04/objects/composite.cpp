#include "composite.h"

void Composite::removeObject(ObjIt &it)
{
    if (!(*it))
    {
        throw ObjectOutOfRangeException();
    }

    this->objects.erase(it);
}

void Composite::addObject(Object *obj)
{
    this->objects.push_back(obj);
}

bool Composite::visible()
{
    bool vis = false;

    for (int i = 0; i < objects.size() && !vis; i++)
    {
        vis = objects[i]->visible();
    }
    return vis;
}
