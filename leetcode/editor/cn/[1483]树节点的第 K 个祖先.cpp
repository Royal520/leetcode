#include<bits/stdc++.h>
#include "util/ListNode.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {

    }
    
    int getKthAncestor(int node, int k) {

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
//leetcode submit region end(Prohibit modification and deletion)
/*
   1   2   3
A 0.91 0.8 0.2         A->1 B->3 c->2
B 0.92 0.5 0.9
C 0.6 0.8 0.5
 */

int main() {
    clock_t start, end;
    start = clock();
    cout <<""<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}