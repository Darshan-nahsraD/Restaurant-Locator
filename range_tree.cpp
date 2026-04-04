#include "range_tree.h"

void RangeTree::build(vector<Point>& points) {
    for (auto p : points) {
        root = avl.insert(root, p.x, p);
    }
}

vector<Point> RangeTree::query(int x1, int x2, int y1, int y2) {
    vector<Point> temp = avl.rangeQuery(root, x1, x2);
    vector<Point> result;

    for (auto p : temp) {
        if (p.y >= y1 && p.y <= y2)
            result.push_back(p);
    }

    return result;
}