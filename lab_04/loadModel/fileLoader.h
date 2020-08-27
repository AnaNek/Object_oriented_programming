#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <fstream>
#include <string.h>
#include <iostream>
#include "baseLoader.h"
#include "modelBuilder.h"
#include "exceptions/loadexception.h"

class FileLoader : public BaseLoader
{
    enum Action
    {
        READ,
        WRITE
    };

public:
    explicit FileLoader(std::string &name) : filename(name) {}
    ~FileLoader() = default;

    FileLoader& operator =(const FileLoader &l);
    void openFile();
    void closeFile();

    Model* openModel(BaseBuilder &) override;
    void saveModel(Model) override;

private:
    std::ifstream in;
    std::ofstream out;
    std::string filename;
    Action action;
};

#endif
