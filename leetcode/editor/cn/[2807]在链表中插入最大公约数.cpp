#include<bits/stdc++.h>
#include "util/ListNode.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b) {
        if (a < b)return gcd(b, a);
        if(a%b==0)return b;
        else return gcd(a-b,b);
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        if(!head||!head->next)return head;
        ListNode* root=head;
        ListNode* then=head->next;
        ListNode* cur=head;
        while (then){
            auto* add=new ListNode(gcd(cur->val,then->val));
            cur->next=add;
            add->next=then;
            cur=then;
            then=then->next;
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<""<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}