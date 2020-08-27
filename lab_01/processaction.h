#ifndef PROCESSACTION_H
#define PROCESSACTION_H

#include "errors.h"
#include "repository.h"
#include "model.h"
#include "transform_points.h"
#include "operations_model.h"
#include "open_model.h"
#include "save_model.h"

error_t processingAction(Repository &repository, operation_t operation);

#endif
