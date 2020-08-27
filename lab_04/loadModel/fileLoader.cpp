#include "fileLoader.h"

void FileLoader::openFile()
{
    if (action == READ)
    {
        this->in.open(this->filename);

        if (!in)
        {
            throw OpenFileException();
        }
    }
    else if (action == WRITE)
    {
        this->out.open(this->filename);

        if (!out)
        {
            throw OpenFileException();
        }
    }
}

void FileLoader::closeFile()
{
    if (this->in.is_open())
    {
        in.close();
    }
    else if (this->out.is_open())
    {
        out.close();
    }
}

Model* FileLoader::openModel(BaseBuilder &builder)
{
    this->action = READ;
    openFile();
    int numVert = 0;
    this->in >> numVert;

    if (numVert < 0)
    {
        throw ReadFileException();
    }

    for (int i = 0; i < numVert; i++)
    {
        double x, y, z;
        this->in >> x >> y >> z;

        if (!in.good())
        {
            throw ReadFileException();
        }

        builder.buildVertice(x, y, z);
    }

    int numEdgs = 0;
    this->in >> numEdgs;

    if (numEdgs < 0)
    {
        throw ReadFileException();
    }

    for (int k = 0; k < numEdgs; k++)
    {
        double i, j;
        this->in >> i >> j;

        if (!in.good())
        {
            throw ReadFileException();
        }

        builder.buildEdges(i, j);
    }

    builder.buildModel();
    closeFile();
    return builder.getModel();
}

void FileLoader::saveModel(Model model)
{
    this->action = WRITE;
    openFile();
    int numVert = model.getPoints().size();
    this->out << numVert << "\n";
    std::vector<Point3D> vert = model.getPoints();

    for (int i = 0; i < numVert; i++)
    {
        this->out << vert[i].x() << " " << vert[i].y() << " " << vert[i].z() << "\n";
    }
    int numEdges = model.getEdges().size();
    this->out << numEdges << "\n";
    std::vector<Edge> edges = model.getEdges();

    for (int i = 0; i < numEdges; i++)
    {
        this->out << edges[i].getFirstInd() << " " << edges[i].getSecondInd() << "\n";
    }
    closeFile();
}

FileLoader& FileLoader::operator =(const FileLoader &l)
{
    this->action = l.action;
    this->filename = l.filename;
    return (*this);
}
