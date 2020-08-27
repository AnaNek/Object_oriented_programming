#ifndef DRAWEREXCEPTION_H
#define DRAWEREXCEPTION_H

#include "baseexception.h"

class NoObjectException : public BaseException
{
public:
    explicit NoObjectException() : BaseException(msg) {}
    explicit NoObjectException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Drawing object error";
};

class NoPointsException : public BaseException
{
public:
    explicit NoPointsException() : BaseException(msg) {}
    explicit NoPointsException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Drawing nodes error";
};

class NoEdgesException : public BaseException
{
public:
    explicit NoEdgesException() : BaseException(msg) {}
    explicit NoEdgesException(const std::string& message) : BaseException(msg + message) {}
};

#endif // DRAWEREXCEPTION_H
