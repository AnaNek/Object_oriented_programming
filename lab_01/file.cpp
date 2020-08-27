#include "file.h"

File initFile()
{
    File file;

    file.action = READFILE;
    file.file = nullptr;

    return file;
}

error_t openFile(File &f, char *filename, const char *action)
{
    error_t er = SUCCESS;

    if ((strcmp(action,"w") != 0) && (strcmp(action, "r") != 0))
    {
        er = INCORRECT_DATA;
        return er;
    }

    f.file = filename;

    if (strcmp(action, "w") == 0)
    {
        f.f_out.open(f.file);
        f.action = WRITEFILE;
    }

    if (strcmp(action, "r") == 0)
    {
        f.f_in.open(f.file);
        f.action = READFILE;
    }

    return er;
}

bool isOpen(File &f)
{
    bool statement = false;

    if ((f.action != READFILE) && (f.action != WRITEFILE))
    {
        return statement;
    }

    if (f.action == WRITEFILE)
    {
        statement = f.f_out.is_open();
    }

    if (f.action == READFILE)
    {
        statement = f.f_in.is_open();
    }
    return statement;
}

void closeFile(File &f)
{
    if (f.action == WRITEFILE)
    {
       f.f_out.close();
    }

    if (f.action == READFILE)
    {
        f.f_in.close();
    }
}

error_t readData(double &data, File &f)
{
    error_t er = SUCCESS;

    f.f_in >> data;

    if (!f.f_in.good())
    {
        er = INCORRECT_DATA;
    }

    return er;
}

error_t readData(int &data, File &f)
{
    error_t er = SUCCESS;

    f.f_in >> data;

    if (!f.f_in.good())
    {
        er = INCORRECT_DATA;
    }

    return er;
}

error_t writeData(File &f, double &data)
{
    error_t er = SUCCESS;

    f.f_out << data;

    if (!f.f_out.good())
    {
        er = INCORRECT_DATA;
    }

    return er;
}

error_t writeData(File &f, int &data)
{
    error_t er = SUCCESS;

    f.f_out << data;

    if (!f.f_out.good())
    {
        er = INCORRECT_DATA;
    }

    return er;
}

error_t writeData(File &f, const char *data)
{
    error_t er = SUCCESS;

    f.f_out << data;

    if (!f.f_out.good())
    {
        er = INCORRECT_DATA;
    }

    return er;
}
