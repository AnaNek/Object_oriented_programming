#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "baseManager.h"
#include "objects/model.h"
#include "loadModel/modelBuilder.h"
#include "loadModel/baseLoader.h"
#include "loadModel/fileLoader.h"
#include "iterators/iterators.h"
#include "exceptions/objectexception.h"

class FileManager : public BaseManager
{
public:
    FileManager() = default;
    ~FileManager() = default;

    Model* openModel(BaseLoader &loader, BaseBuilder &builder);
    void saveModel(BaseLoader &loader, ObjIt &itBegin, ObjIt &itEnd);
};

#endif
