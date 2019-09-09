#ifndef BFS_H
#define BFS_H

#include <src/Algorithms/motionplanningalgorithms.h>

using namespace std;

class Bfs : public MotionPlanningAlgorithms
{
public:
  Bfs(vector<vector<int>> &maze);
  vector<Point*> search(Point* start, Point* target);
private:
  vector<vector<int>> maze;
};

#endif // BFS_H
