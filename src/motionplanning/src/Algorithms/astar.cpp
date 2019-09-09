#include "astar.h"
#include <iostream>

using namespace std;

Astar::Astar(vector<vector<int>> &maze)
{
    this->maze = maze;
}

int Astar::heuristics (Point node, Point target) {
    //Manhattan Distance
    int dx = abs(node.x - target.x);
    int dy = abs(node.y - target.y);
    return dx + dy;
}

vector<Point*> Astar::search(Point* start, Point* target) {
    int m = maze.size();
    int n = maze[0].size();
    if (m == 0 || n == 0) {
        return {};
    }
    set<Point*> inOpenList;
    priority_queue<Point*,vector<Point*>,comp> OpenList;
    vector<Point*> path;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    OpenList.push(start);
    inOpenList.insert(start);
    int pathLength = 0;
    while (!OpenList.empty()) {
        Point* current = OpenList.top(); OpenList.pop();
        path.push_back(current);
        visited[current->x][current->y] = true;
        if (*current == *target) {
            return path;
        }
        for (int j = 0; j < dirs.size(); j++) {
            int xx = current->x + dirs[j].first;
            int yy = current->y + dirs[j].second;
            if (xx >= m || xx < 0 || yy >= n || yy < 0 || visited[xx][yy] || maze[xx][yy] == 1) {
                continue;
            }
            Point *neighbor = new Point(xx,yy);
            int cost = current->cost_g + 1; //calculate g = g_past + newCost
            neighbor->cost_g = cost;
            if (inOpenList.count(neighbor) > 0) {
                neighbor->cost_f = neighbor->cost_g + heuristics(*neighbor,*target);
            }else{
                neighbor->cost_f = neighbor->cost_g + heuristics(*neighbor,*target);
                OpenList.push(neighbor);
                inOpenList.insert(neighbor);
                neighbor->parent = current;
            }
        }
        pathLength++;
    }
    return {};
}
