#ifndef ITERATORS_H
#define ITERATORS_H

#include "objects/object.h"
#include "objects/position.h"
#include "objects/camera.h"
#include <vector>

typedef std::vector<Object*>::iterator ObjIt;
typedef std::vector<Position>::iterator PosIt;

#endif
