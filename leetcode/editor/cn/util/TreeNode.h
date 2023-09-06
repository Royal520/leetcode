//
// Created by gl on 2023/9/6.
//
#include<bits/stdc++.h>

using namespace std;
#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 通过层序号遍历构建二叉树,第一个不参与，null节点的值为-1；
 */
TreeNode* level(vector<int>& nums){

}
#endif //LEETCODE_TREENODE_H
