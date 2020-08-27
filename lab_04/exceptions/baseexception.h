#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

class BaseException : public std::exception
{
public:
    BaseException();
    explicit BaseException(const char* msg): msg(msg) {}
    explicit BaseException(const std::string& msg) : msg(msg) {}

    virtual const char* what() const noexcept override
    {
        return msg.c_str();
    }
protected:
    std::string msg;
};

#endif
