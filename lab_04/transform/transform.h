#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "objects/object.h"
#include "objects/model.h"
#include "iterators/iterators.h"

class BaseTransform
{
public:
    BaseTransform(double i, double j, double k) : first(i), second(j), third(k) {}
    virtual ~BaseTransform() = default;

    virtual void transform(Object*) = 0;

    double firstParam() {return first;}
    double secondParam() {return second;}
    double thirdParam() {return third;}

protected:
    double first;
    double second;
    double third;
};

class Mover : public BaseTransform
{
public:
    Mover(double dx, double dy, double dz) : BaseTransform(dx, dy, dz) {}
    ~Mover() = default;

    void transform(Object *) override;
};

class Scaler : public BaseTransform
{
public:
    Scaler(double kx, double ky, double kz) : BaseTransform(kx, ky, kz) {}
    ~Scaler() = default;

    void transform(Object *) override;
};

class Rotater : public BaseTransform
{
public:
    Rotater(double ox, double oy, double oz) : BaseTransform(ox, oy, oz) {}
    ~Rotater() = default;

    void transform(Object *) override;
};

#endif
