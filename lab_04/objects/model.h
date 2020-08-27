#ifndef MODEL_H
#define MODEL_H

#include "object.h"
#include "point3d.h"
#include "edge.h"
#include <vector>

class Model : public VisibleObject
{
public:
    Model() {}
    Model(std::vector<Point3D> &verts, std::vector<Edge> &edges): verticies(verts), edges(edges) {}
    Model(const Model &model);
    Model(Model&& model);
    ~Model() { }

    Model& operator =(const Model& model);
    Model& operator =(Model&& model);

    std::vector<Edge> getEdges() const {return edges;}
    std::vector<Point3D> getPoints() const {return verticies;}

    void setPoints(std::vector<Point3D> p) {this->verticies = p;}
    void setEdges(std::vector<Edge> e) {this->edges = e;}

    void addEdge(const Edge &edge) {edges.push_back(edge);}
    void addPoint(const Point3D &point) {verticies.push_back(point);}

private:
    std::vector<Point3D> verticies;
    std::vector<Edge> edges;
};

#endif
