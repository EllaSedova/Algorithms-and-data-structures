#include <iostream>
#include <vector>
#include <chrono>
#include "AVL/AVL.h"

using vec = std::vector<int>;
using namespace std;

Node *Clone(vec vector, AVL tree) {
    Node *root = NULL;
    for (int elem: vector) {
        root = tree.insertNode(root, elem);
        //cout<<"el  "<<elem<<'\n';
    }
    return root;
}

double Find_res(const vec &vect) {
    int res = 0;
    for (int elem: vect) {
        res += elem;
    }
    return (double) res / vect.size();
}

void which_func(vec &vector, Node *root, AVL tree) {
    cout << "Which func?" << '\n';
    cout << "Print the operation time of the search - 1\n";
    cout << "Print the operation time of the element insertion - 2\n";
    cout << "Get height - 3\n";
    char str;
    int b;
    vec res;
    while (str != '1' && str != '2' && str != '3') {
        cin >> str;
    }
    switch (str) {

        case '1': {
            for (int i = 0; i < 100; i++) {
                b = rand() % 50000;
                auto start = chrono::steady_clock::now();
                tree.Search(root, b);
                auto end = chrono::steady_clock::now();
                res.push_back(chrono::duration_cast<chrono::nanoseconds>(end - start).count());

            }
            cout << "Time:    " << Find_res(res) << '\n';
            break;
        }

        case '2': {
            for (int i = 0; i < 100; i++) {
                vec oldvec = vector;
                Node *nroot = Clone(oldvec, tree);
                b = rand() % 50000;
                auto start = chrono::steady_clock::now();
                nroot = tree.insertNode(nroot, b);
                auto end = chrono::steady_clock::now();
                res.push_back(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
            }
            cout << "Time:    " << Find_res(res) << '\n';
            break;
        }

        case '3': {
            cout << "Height:  " << tree.getHeight(root) - 1 << '\n';
            //tree.printTree(root, "", true);
            break;
        }
    }
}

void createf(std::string filename, vec &vector) {
    fstream file;
    string line;
    file.open(filename, std::ios_base::in);
    int a;
    if (!file.is_open())
        cout << "Can't open file <" << filename << ">" << '\n';
    else
    {
        while (file >> a)
            vector.push_back(a);
    }
}

void number_elem(vec &vector) {

    cout << "How many vertices are there in the tree[10/100/1000/5000/10000/50000/100000]?" << '\n';
    cout << "If 10 - 0\n" << "If 100 - 1\n" << "If 1000 - 2\n" << "If 5000 - 3\n" << "If 10000 - 4\n"
         << "If 50000 - 5\n"
         << "If 100000 - 6\n";
    char str;
    while (str != '0' && str != '1' && str != '2' && str != '3' && str != '4' && str != '5' && str != '6')
        cin >> str;
    switch (str) {
        case '0': {
            createf("ten.txt", vector);
            break;
        }
        case '1': {
            createf("1_hundred.txt", vector);
            break;
        }
        case '2': {
            createf("1_thousand.txt", vector);
            break;
        }
        case '3': {
            createf("5_thousand.txt", vector);
            break;
        }
        case '4': {
            createf("10_thousand.txt", vector);
            break;
        }
        case '5': {
            createf("50_thousand.txt", vector);
            break;
        }
        case '6': {
            createf("100_thousand.txt", vector);
            break;
        }
    }
}

int main() {
    AVL tree;
    vec results;
    vec vector;
    results.reserve(100);
    Node *root = NULL;
    number_elem(vector);

    for (int elem: vector) {
        root = tree.insertNode(root, elem);
    }
    which_func(vector, root, tree);
}
