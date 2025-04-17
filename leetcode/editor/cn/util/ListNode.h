//
// Created by gl on 2023/9/13.
//
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *root) {
    ListNode *cur = root;
    while (cur) {
        cout << cur->val;
        if (cur->next)cout << "-->";
        cur = cur->next;
    }
    cout<<endl;
}

ListNode *init_by_arr(vector<int> nums) {
    if (nums.empty())return nullptr;
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next=new ListNode(nums[0]);
    ListNode *cur = dummyNode->next;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next=new ListNode(nums[i]);
        cur=cur->next;
    }
    return dummyNode->next;
}

#endif //LEETCODE_LISTNODE_H
