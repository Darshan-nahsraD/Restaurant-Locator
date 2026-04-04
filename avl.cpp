#include "avl.h"
#include <algorithm>

int height(Node* n) {
    return n ? n->height : 0;
}

int balance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVL::insert(Node* root, int key, Point p) {
    if (!root) return new Node(key, p);

    if (key < root->key)
        root->left = insert(root->left, key, p);
    else if (key > root->key)
        root->right = insert(root->right, key, p);
    else {
        root->points.push_back(p);
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int bf = balance(root);

    if (bf > 1 && key < root->left->key)
        return rotateRight(root);

    if (bf < -1 && key > root->right->key)
        return rotateLeft(root);

    if (bf > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (bf < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

vector<Point> AVL::rangeQuery(Node* root, int l, int r) {
    vector<Point> rem;
    if (!root) return rem;
    if (root->key >= l && root->key <= r) {
        rem.insert(rem.end(), root->points.begin(), root->points.end());
    }
    if (l < root->key) {
        auto left = rangeQuery(root->left, l, r);
        rem.insert(rem.end(), left.begin(), left.end());
    }
    if (r > root->key) {
        auto right = rangeQuery(root->right, l, r);
        rem.insert(rem.end(), right.begin(), right.end());
    }
    return rem;
}
