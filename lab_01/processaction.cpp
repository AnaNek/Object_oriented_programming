#include "processaction.h"

error_t processingAction(Repository &repository, operation_t operation)
{
    static Model model = initModel();

    error_t er = SUCCESS;

    switch (operation)
    {
    case(OPENNING):
        er = openModel(model, repository);
        break;

    case(SCALE):
        er = scaleModel(model, repository);
        break;

    case(MOVING):
        er = moveModel(model, repository);
        break;

    case(ROTATE):
        er = rotateModel(model, repository);
        break;

    case(SAVING):
        er = saveModel(model, repository);
        break;

    case(TRANSFORM):
        er = transformPoints(&repository.points, repository.numberPoints,\
                             &repository.ind, repository.numberInd, model);
        break;

    case(EXIT):
        freeModel(model);
        break;

    default:
        break;
    }

    return er;
}
