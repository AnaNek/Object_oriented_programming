#ifndef OBJECTEXCEPTION_H
#define OBJECTEXCEPTION_H

#include "baseexception.h"

class ObjectOutOfRangeException : public BaseException
{
public:
    explicit ObjectOutOfRangeException() : BaseException(msg) {}
    explicit ObjectOutOfRangeException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Out of range error";
};

#endif
