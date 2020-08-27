#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include "errors.h"
#include <string.h>

#define READFILE  1
#define WRITEFILE 2

struct File
{
    std::ifstream f_in;
    std::ofstream f_out;
    int action;
    char *file;
};

File initFile();
error_t openFile(File &f, char *filename, const char *action);
bool isOpen(File &f);
void closeFile(File &f);
error_t readData(double &data, File &f);
error_t readData(int &data, File &f);
error_t writeData(File &f, double &data);
error_t writeData(File &f, int &data);
error_t writeData(File &f, const char *data);

#endif
