#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <time.h>
#include <windows.h>
#include "Node.h"

using vec = std::vector<int>;
using namespace std;

class AVL {
public:
    Node *node;

// Calculate height
    int height(Node *N);

// New node creation
    Node *newNode(int key);

// Rotate right
    Node *rightRotate(Node *y);

// Rotate left
    Node *leftRotate(Node *x);

// Get the balance factor of each node
    int getBalanceFactor(Node *N);

// Insert a node
    Node *insertNode(Node *node, int key);

// Print the tree
    void printTree(Node *root, string indent, bool last);

    bool Search(Node *root, int key);

    Node *Clone(vec vector);

    int getHeight(Node *t);

};