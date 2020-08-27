#ifndef TRANSFORMEREXCEPTION_H
#define TRANSFORMEREXCEPTION_H

#include "baseexception.h"

class ObjectTransformingException : public BaseException
{
public:
    explicit ObjectTransformingException() : BaseException(msg) {}
    explicit ObjectTransformingException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Transforming object error";
};

class NodesTransformingException : public BaseException
{
public:
    explicit NodesTransformingException() : BaseException(msg) {}
    explicit NodesTransformingException(const std::string& message) : BaseException(msg + message) {}
private:
    static constexpr const char* msg = "Transforming nodes error";
};

#endif
