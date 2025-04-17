#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>dp;
        for (const auto &item: words){
            int t=0;
            for (const auto &c: item){
                t|=1<<(c-'a');
            }
            dp.push_back(t);
        }
        int ans=0;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = i+1; j < dp.size() ; ++j) {
                if((dp[i]&dp[j])==0){
                    int temp=words[i].size()*words[j].size();
                    ans= max(ans,temp);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.maxProduct(*new vector<string>({"abcw","baz","foo","bar","xtfn","abcdef"}))<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}