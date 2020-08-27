#ifndef BUILDEREXCEPTION_H
#define BUILDEREXCEPTION_H

#include "baseexception.h"

class BuilderException : public BaseException
{
public:
    explicit BuilderException() : BaseException(msg) {}
    explicit BuilderException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Building object error";
};

#endif
