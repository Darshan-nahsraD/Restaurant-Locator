#ifndef AVL_H
#define AVL_H

#include <vector>
using namespace std;

struct Point {
    int x, y;
};

struct Node {
    int key;
    vector<Point> points;
    Node* left;
    Node* right;
    int height;

    Node(int k, Point p) {
        key = k;
        points.push_back(p);
        left = right = NULL;
        height = 1;
    }
};

class AVL {
public:
    Node* insert(Node* root, int key, Point p);
    vector<Point> rangeQuery(Node* root, int l, int r);
};

#endif