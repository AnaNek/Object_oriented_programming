#ifndef ALLOCATE_MODEL_H
#define ALLOCATE_MODEL_H

#include "model.h"

error_t allocateModel(Model &model, int numberEdges, int numberVerteces);
void freeModel(Model &model);

#endif
