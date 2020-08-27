#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fasad.h"
#include "commands/command.h"

class Controller
{
public:
    Controller() { this->fasad = new Fasad(); }
    ~Controller() = default;

    void process(BaseCommand &command) { command.execute(fasad); }
private:
    Fasad* fasad;
};

#endif
