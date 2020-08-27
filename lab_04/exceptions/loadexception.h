#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "baseexception.h"

class OpenFileException : public BaseException
{
public:
    explicit OpenFileException() : BaseException(msg) {}
    explicit OpenFileException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Opening file error";
};

class CloseFileException : public BaseException
{
public:
    explicit CloseFileException() : BaseException(msg) {}
    explicit CloseFileException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Closing file error";
};

class ReadFileException : public BaseException
{
public:
    explicit ReadFileException() : BaseException(msg) {}
    explicit ReadFileException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Reading file error";
};

#endif
