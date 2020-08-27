#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "objects/object.h"
#include "objects/position.h"
#include "objects/camera.h"
#include "objects/composite.h"
#include "iterators/iterators.h"

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    void addObject(Object *obj) {activeComposite.addObject(obj);}
    void removeObject(ObjIt &it) {activeComposite.removeObject(it);}

    void addCamera(Camera *obj) {activeComposite.addObject(obj);}
    void removeCamera(ObjIt &it) {activeComposite.removeObject(it);}

    ObjIt objectBegin() {return activeComposite.begin();}
    ObjIt objectEnd() {return activeComposite.end();}

    PosIt posBegin() {return positions.begin();}
    PosIt posEnd() {return positions.end();}

private:
    Composite activeComposite;
    std::vector<Position> positions;
};

#endif
