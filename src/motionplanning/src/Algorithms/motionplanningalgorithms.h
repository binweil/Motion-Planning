#ifndef MOTIONPLANNINGALGORITHMS_H
#define MOTIONPLANNINGALGORITHMS_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

struct Point{
    int x = -1;
    int y = -1;
    bool inOpenList;
    double cost_h;
    double cost_g;
    double cost_f;
    Point *parent;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        this->inOpenList = false;
        cost_f = 0;
        cost_g = 0;
        cost_h = 0;
        parent = NULL;
    }
    friend bool operator < (Point A, Point B) {
        return A.cost_g <= B.cost_g;
    }
    friend bool operator == (Point A, Point B) {
        return (A.x == B.x && A.y == B.y);
    }
};

using namespace std;

class MotionPlanningAlgorithms {
public:
    vector<pair<int,int>> dirs = {make_pair(1,0),
                                 make_pair(-1,0),
                                 make_pair(0,1),
                                 make_pair(0,-1)};

    virtual vector<Point*> search(Point* start, Point* target) {}
};

#endif // MOTIONPLANNINGALGORITHMS_H
