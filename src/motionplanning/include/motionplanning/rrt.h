#ifndef RRT_H
#define RRT_H

#include <src/Algorithms/motionplanningalgorithms.h>

class RRT : MotionPlanningAlgorithms
{
public:
  RRT(vector<vector<int>> &maze);
  vector<Point*> search(Point* start, Point* target);
private:
  vector<vector<int>> maze;
};

#endif // RRT_H
