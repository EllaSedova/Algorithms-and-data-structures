#include <iostream>
#include <vector>
#include <chrono>
#include "AVL.h"

using vec = std::vector<int>;
using namespace std;

int AVL::height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// New node creation
Node *AVL::newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Rotate right
Node *AVL::rightRotate(Node *y) {
    //cout<<"RIGHT"<<'\n';
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Rotate left
Node *AVL::leftRotate(Node *x) {
    //cout<<"LEFT"<<'\n';
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Get the balance factor of each node
int AVL::getBalanceFactor(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert a node
Node *AVL::insertNode(Node *node, int key) {
    // Find the correct postion and insert the node
    if (node == NULL)
        return (newNode(key));
    if (key < node->key) {
        //cout << "key<  " << node->key << '\n';
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        //cout << "key>  " << node->key << '\n';
        node->right = insertNode(node->right, key);
    } else
        return node;//если элемент уже имеется

    // Update the balance factor of each node and
    // balance the tree
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceFactor = getBalanceFactor(node);
    //cout << "node:  " << node->key << '\n';
    //cout << "b:  " << balanceFactor << '\n';
    if (balanceFactor > 1) {
        //cout<<"balf>1" <<'\n';
        if (key < node->left->key) {
            return rightRotate(node);
        } else if (key > node->left->key) {
            // cout<<"BIG ROTATE" <<'\n';
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        //cout<<"balf<-1" <<'\n';
        if (key > node->right->key) {
            return leftRotate(node);
        } else if (key < node->right->key) {
            // cout<<"BIG ROTATE" <<'\n';
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

// Print the tree
void AVL::printTree(Node *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << "[" << getBalanceFactor(root) << "]" << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

bool AVL::Search(Node *root, int key) {
    if (root == nullptr) {
        return 0;
    }
    if (key < root->key) {
        return Search(root->left, key);
    } else if (key > root->key) {
        return Search(root->right, key);
    }
    return key;
}

Node *AVL::Clone(vec vector) {
    Node *root = NULL;
    for (int elem: vector) {
        root = insertNode(root, elem);
        //cout<<"el  "<<elem<<'\n';
    }
    return root;
}

int AVL::getHeight(Node *t) {
    if (t == NULL)
        return 0;
    else
        return max(getHeight(t->left), getHeight(t->right)) + 1;
}



