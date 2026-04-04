#ifndef RANGE_TREE_H
#define RANGE_TREE_H

#include "avl.h"

class RangeTree {
public:
    Node* root;
    AVL avl;

    RangeTree() {
        root = NULL;
    }

    void build(vector<Point>& points);
    vector<Point> query(int x1, int x2, int y1, int y2);
};

#endif