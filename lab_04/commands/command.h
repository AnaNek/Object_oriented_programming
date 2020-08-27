#ifndef COMMAND_H
#define COMMAND_H

#include "managers/fasad.h"
#include "drawer/drawer.h"
#include "loadModel/baseLoader.h"
#include "loadModel/fileLoader.h"
#include "loadModel/modelBuilder.h"
#include "objects/camera.h"
#include "transform/transform.h"

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;
    virtual void execute(Fasad*) = 0;
};

class OpenCommand : public BaseCommand
{
public:
    OpenCommand(std::string name): filename(name) {}
    ~OpenCommand() = default;
    virtual void execute(Fasad*) override;

private:
    std::string filename;
};

class SaveCommand : public BaseCommand
{
public:
    SaveCommand(std::string name): filename(name) {}
    ~SaveCommand() = default;
    virtual void execute(Fasad*) override;

private:
    std::string filename;
};

class DrawCommand : public BaseCommand
{
public:
    DrawCommand(Drawer& d): drawer(d) {}
    ~DrawCommand() = default;
    virtual void execute(Fasad*) override;

private:
    Drawer drawer;
};

class MoveCommand : public BaseCommand
{
public:
    MoveCommand(double dx, double dy, double dz): dx(dx), dy(dy), dz(dz) {}
    ~MoveCommand() = default;
    virtual void execute(Fasad*) override;

private:
    double dx;
    double dy;
    double dz;
};

class ScaleCommand : public BaseCommand
{
public:
    ScaleCommand(double kx, double ky, double kz): kx(kx), ky(ky), kz(kz) {}
    ~ScaleCommand() = default;
    virtual void execute(Fasad*) override;

private:
    double kx;
    double ky;
    double kz;
};

class RotateCommand : public BaseCommand
{
public:
    RotateCommand(double ox, double oy, double oz): ox(ox), oy(oy), oz(oz) {}
    ~RotateCommand() = default;
    virtual void execute(Fasad*) override;

private:
    double ox;
    double oy;
    double oz;
};

class AddCameraCommand : public BaseCommand
{
public:
    AddCameraCommand(Camera *c): cam(c) {}
    ~AddCameraCommand() = default;
    virtual void execute(Fasad*) override;

private:
    Camera *cam;
};
#endif
