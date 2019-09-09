#include "bfs.h"

Bfs::Bfs(vector<vector<int>> &maze)
{
    this->maze = maze;
}

vector<Point*> Bfs::search(Point* start, Point* target) {
    int m = maze.size();
    int n = maze[0].size();
    if (m == 0 || n == 0) {
        return {};
    }
    queue<Point*> Q;
    vector<Point*> path;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    Q.push(start);
    while (!Q.empty()) {
        Point* current = Q.front(); Q.pop();
        visited[current->x][current->y] = true;
        path.push_back(current);
        if (*current == *target) {
            return path;
        }
        for (int i = 0; i < dirs.size(); i++) {
            int xx = current->x + dirs[i].first;
            int yy = current->y + dirs[i].second;
            if (xx >= m || xx < 0 || yy >= n || yy < 0 || visited[xx][yy] || maze[xx][yy] == 1) {
                continue;
            }
            Point* neighbor = new Point(xx,yy);
            Q.push(neighbor);
            neighbor->parent = current;
            visited[xx][yy] = true;
        }
    }
    return {};
}
