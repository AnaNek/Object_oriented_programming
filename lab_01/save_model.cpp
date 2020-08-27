#include "save_model.h"

error_t writeNumberVertices(int &numberVertices, File &f)
{
    error_t er = SUCCESS;

    bool res = false;

    res = writeData(f, numberVertices) || writeData(f, "\n");

    if (res)
    {
        er = INCORRECT_DATA;
    }

    if (er == SUCCESS)
    {
        if (numberVertices < 2)
        {
            er = INCORRECT_DATA;
        }
    }
    return er;
}

error_t writeNumberEdges(int &numberEdges, File &f)
{
    error_t er = SUCCESS;

    bool res = false;

    res = writeData(f, numberEdges) || writeData(f, "\n");

    if (res)
    {
        er = INCORRECT_DATA;
    }

    if (er == SUCCESS)
    {
        if (numberEdges < 2)
        {
            er = INCORRECT_DATA;
        }
    }
    return er;
}

error_t writeEdges(Edge *edges, int numberEdges, File &f)
{
    error_t er = SUCCESS;

    for (int i = 0; (i < numberEdges / 2) && (er == SUCCESS); i++)
    {
        bool res = false;

        res = writeData(f, edges[i].first_index) || writeData(f, " ") \
                || writeData(f, edges[i].second_index) || writeData(f, "\n");

        if (res)
        {
            er = INCORRECT_DATA;
        }
    }
    return er;
}

error_t writeVertices(Vertice *vertices, int numberVertices, File &f)
{
    error_t er = SUCCESS;

    for (int i = 0; (i < numberVertices) && (er == SUCCESS); i++)
    {
        bool res = false;
        res = writeData(f, vertices[i].x) || writeData(f, " ") \
                || writeData(f, vertices[i].y) || writeData(f, " ")\
                || writeData(f, vertices[i].z) || writeData(f, "\n");
        if (res)
        {
            er = INCORRECT_DATA;
        }

    }
    return er;
}

error_t saveModel(Model &model, Repository &repository)
{
    error_t er = SUCCESS;

    File f_out = initFile();

    er = openFile(f_out, repository.file, "w");

    if (!isOpen(f_out))
    {
        er = OPEN_ERR;
        return er;
    }

    if (model.load == false)
    {
        er = NOT_LOADED;
    }

    if (er == SUCCESS)
    {
        er = writeNumberVertices(model.numberVertices, f_out);
    }

    if (er == SUCCESS)
    {
        er = writeNumberEdges(model.numberEdges, f_out);
    }

    if (er == SUCCESS)
    {
        er = writeVertices(model.vertices, model.numberVertices, f_out);
    }

    if (er == SUCCESS)
    {
        er = writeEdges(model.edges, model.numberEdges, f_out);
    }

    closeFile(f_out);
    return er;
}
