#include "edge.h"

Edge::Edge()
{
    this->firstInd = 0;
    this->secondInd = 0;
}

int Edge::getFirstInd()
{
    return firstInd;
}

int Edge::getSecondInd()
{
    return secondInd;
}

void Edge::setFirstInd(int i)
{
    this->firstInd = i;
}

void Edge::setSecondInd(int j)
{
    this->secondInd = j;
}
