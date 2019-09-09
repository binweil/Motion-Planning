#ifndef ASTAR_H
#define ASTAR_H


#include <src/Algorithms/motionplanningalgorithms.h>

using namespace std;

class Astar : public MotionPlanningAlgorithms
{
public:
    struct comp{
        bool operator ()(Point* A, Point* B) {
            return A->cost_f >= B->cost_f;
        }
    };

    Astar(vector<vector<int>> &maze);
    int heuristics (Point node, Point target);
    vector<Point*> search(Point *start, Point *target);
private:
    vector<vector<int>> maze;
};

#endif // ASTAR_H
