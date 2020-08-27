#include "open_model.h"

error_t readNumberEdges(int &numberEdges, File &f)
{
    error_t er = SUCCESS;

    er = readData(numberEdges, f);

    if (er == SUCCESS)
    {
        if (numberEdges < 2)
        {
            er = INCORRECT_DATA;
        }
    }
    return er;
}

error_t readEdges(Edge *edges, int numberEdges, File &f)
{
    error_t er = SUCCESS;

    for (int i = 0; (i < numberEdges / 2) && (er == SUCCESS); i++)
    {
        if (readData(edges[i].first_index, f) \
              || readData(edges[i].second_index, f))
        {
            er = INCORRECT_DATA;
        }
    }
    return er;
}

error_t readVertices(Vertice *vertices, int numberVertices, File &f)
{
    error_t er = SUCCESS;

    for (int i = 0; (i < numberVertices) && (er == SUCCESS); i++)
    {
        if (readData(vertices[i].x, f) || readData(vertices[i].y, f) \
              || readData(vertices[i].z, f))
        {
            er = INCORRECT_DATA;
        }

    }
    return er;
}

error_t readNumberVertices(int &numberVertices, File &f)
{
    error_t er = SUCCESS;

    er = readData(numberVertices, f);

    if (er == SUCCESS)
    {
        if (numberVertices < 2)
        {
            er = INCORRECT_DATA;
        }
    }
    return er;
}

error_t openModel(Model &model, Repository &repository)
{
    error_t er = SUCCESS;

    File f_in = initFile();

    er = openFile(f_in, repository.file, "r");

    Model buf = initModel();

    if (!isOpen(f_in))
    {
        model.load = false;
        er = OPEN_ERR;
        return er;
    }

    if (er == SUCCESS)
    {
        er = readNumberVertices(buf.numberVertices, f_in);
    }

    if (er == SUCCESS)
    {
        er = readNumberEdges(buf.numberEdges, f_in);
    }

    if (er == SUCCESS)
    {
        er = allocateModel(buf, buf.numberEdges, buf.numberVertices);
    }
    if (er == SUCCESS)
    {
        er = readVertices(buf.vertices, buf.numberVertices, f_in);
    }
    else
    {
        if (er == MEM_ERR)
        {
            model.load = false;
            closeFile(f_in);
            return er;
        }
    }

    if (er == SUCCESS)
    {
        er = readEdges(buf.edges, buf.numberEdges, f_in);
    }

    if (er == SUCCESS)
    {
        buf.load = true;
        if (model.load == true)
        {
            freeModel(model);
        }

        model = buf;
    }
    else
    {
        freeModel(buf);
    }

    closeFile(f_in);
    return er;
}
