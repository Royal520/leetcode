//
// Created by gl on 2024/2/17.
//

#ifndef LEETCODE_NODE_H
#define LEETCODE_NODE_H
#include "vector"
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


#endif //LEETCODE_NODE_H
