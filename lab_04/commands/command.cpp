#include "command.h"

void OpenCommand::execute(Fasad *fasad)
{
    FileLoader loader(filename);
    ModelBuilder builder;
    fasad->requestOpenModel(loader, builder);
}

void SaveCommand::execute(Fasad *fasad)
{
    FileLoader loader(filename);
    fasad->requestSaveModel(loader);
}

void AddCameraCommand::execute(Fasad *fasad)
{
    fasad->requestAddCamera(this->cam);
}

void DrawCommand::execute(Fasad *fasad)
{
    fasad->requestDraw(drawer);
}

void MoveCommand::execute(Fasad *fasad)
{
    Mover mover = Mover(this->dx, this->dy, this->dz);
    fasad->requestTransform(mover);
}

void RotateCommand::execute(Fasad *fasad)
{
    Rotater rot = Rotater(this->ox, this->oy, this->oz);
    fasad->requestTransform(rot);
}

void ScaleCommand::execute(Fasad *fasad)
{
    Scaler sc = Scaler(this->kx, this->ky, this->kz);
    fasad->requestTransform(sc);
}
