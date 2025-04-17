#include<bits/stdc++.h>
#include "util/ListNode.h"
#include "Node.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            for (int n = q.size(); n--;) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                for (auto c : node->children) {
                    q.push(c);
                }
            }
            ans.emplace_back(vals);
        }
        return ans;
    }

    bool isPrefixAndSuffix(string &str1, string &str2){
        if (str1.length()>str2.length())return false;
        int l2=str2.length();
        int l1=str1.length();
        for (int i = 0; i < l1; ++i) {
            if(str1[i]!=str2[i]||str1[i]!=str2[l2-l1+i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int res=0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if (isPrefixAndSuffix(words[i],words[j]))
                    res++;
            }
        }
        return res;
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