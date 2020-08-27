#include "fileManager.h"

Model* FileManager::openModel(BaseLoader &loader, BaseBuilder &builder)
{
    Model* model = loader.openModel(builder);
    return model;
}

void FileManager::saveModel(BaseLoader &loader, ObjIt &itBegin, ObjIt &itEnd)
{
    for (ObjIt it = itBegin; it != itEnd; it++)
    {
        if (!*it)
        {
            throw ObjectOutOfRangeException();
        }

        Model *model = (Model*)(*it);
        loader.saveModel(*model);
    }
}
