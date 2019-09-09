#ifndef DFS_H
#define DFS_H

#include "motionplanningalgorithms.h"

using namespace std;

class Dfs : public MotionPlanningAlgorithms
{
public:
  Dfs(vector<vector<int>> &maze);
  vector<Point*> search(Point* start, Point* target);
  void DepthFirstSearch(vector<Point*> &res, vector<Point*> &path, vector<vector<bool>> &visited, Point* current, Point *target);
private:
  vector<vector<int>> maze;
};

#endif // DFS_H
