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
    ListNode* reverseList(ListNode* head) {
        if (!(head&&head->next))return head;
        auto* dummyNode=new ListNode(0);
        dummyNode->next=head;
        ListNode* pre=head;
        ListNode* cur=head->next;
        while (cur){
            pre->next=cur->next;
            cur->next=dummyNode->next;
            dummyNode->next=cur;
            cur=pre->next;
        }
        return dummyNode->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    print(init_by_arr({1,2,3,4,5}));
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}