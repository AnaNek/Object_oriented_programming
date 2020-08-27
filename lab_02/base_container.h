#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H

class BaseContainer
{
public:
    virtual void clear() = 0;
    virtual size_t size()  = 0;
};

#endif
