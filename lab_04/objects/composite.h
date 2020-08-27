#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"
#include "iterators/iterators.h"
#include "exceptions/objectexception.h"
#include <vector>

class Composite : public Object
{
public:
    Composite() = default;
    ~Composite() = default;

    bool visible() override;

    void addObject(Object *obj);
    void removeObject(ObjIt &it);

    ObjIt begin() { return objects.begin(); }
    ObjIt end() { return objects.end(); }

private:
    std::vector<Object*> objects;
};

#endif
