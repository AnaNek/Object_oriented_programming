#include "drawManager.h"

void DrawManager::drawObjects(BaseDrawer &drawer, ObjIt &itBegin, ObjIt &itEnd)
{
    for (ObjIt it = itBegin; it != itEnd; ++it)
    {
        if (!(*it))
        {
            throw ObjectOutOfRangeException();
        }

        if ((*it)->visible())
        {
            Model *model = (Model*)(*it);
            std::vector<Edge> edges = model->getEdges();
            if (edges.empty())
            {
                throw NoEdgesException();
            }

            std::vector<Point3D> points = model->getPoints();
            if (points.empty())
            {
                throw NoPointsException();
            }

            for (size_t i = 0; i < edges.size(); ++i)
            {
                Point3D first = points[edges[i].getFirstInd()];
                Point3D second = points[edges[i].getSecondInd()];
                Point2D p1 = first.toPoint2D();
                Point2D p2 = second.toPoint2D();
                drawer.drawLine(p1, p2);
            }
        }
    }
}
