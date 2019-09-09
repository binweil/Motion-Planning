#include "dfs.h"

Dfs::Dfs(vector<vector<int>> &maze)
{
    this->maze = maze;
}

vector<Point*> Dfs::search(Point* start, Point *target) {
    int m = maze.size();
    int n = maze[0].size();
    if (m == 0 || n == 0) {
        return {};
    }
    vector<Point*> res;
    vector<Point*> path;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    DepthFirstSearch(res,path,visited,start,target);
    return res;
}

void Dfs::DepthFirstSearch(vector<Point*> &res, vector<Point*> &path, vector<vector<bool>> &visited, Point* current, Point *target) {
    if (current == NULL) {
        return;
    }
    path.push_back(current);
    visited[current->x][current->y] = true;
    if (*current == *target) {
        res = path;
        return;
    }
    for (int i = 0; i < dirs.size(); i++) {
        int xx = current->x + dirs[i].first;
        int yy = current->y + dirs[i].second;
        Point* neighbor = new Point(xx,yy);
        if (xx >= maze.size() || yy >= maze[0].size() || xx < 0 || yy < 0 || visited[xx][yy] || maze[xx][yy] == 1) {
            continue;
        }
        neighbor->parent = current;
        DepthFirstSearch(res,path,visited,neighbor,target);
    }
    path.pop_back();
}
