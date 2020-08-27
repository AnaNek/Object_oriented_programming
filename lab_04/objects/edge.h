#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
    Edge();
    Edge(const int i, const int j) : firstInd(i), secondInd(j) {}

    int getFirstInd();
    int getSecondInd();

    void setFirstInd(int);
    void setSecondInd(int);

private:
    int firstInd;
    int secondInd;
};

#endif
