#include <iostream>
#include "range_tree.h"

using namespace std;

int main() {

    vector<Point> restaurants = {
        {1,2}, {3,4}, {5,6}, {7,8}, {2,5}, {6,3}
    };

    RangeTree tree;
    tree.build(restaurants);

    int x1 = 2, x2 = 6;
    int y1 = 3, y2 = 6;

   
}