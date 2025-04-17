#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(n*k<target)return 0;
        vector<vector<int>>dp(n+1,vector<int>(n*k+1));
        int mod=1e9+7;
        for (int i = 1; i < k+1; ++i) {
            dp[1][i]=1;
        }
        for (int i = 2; i < n+1; ++i) {
            int end=min(k*i,target)+1;
            for (int j = i; j < end; ++j) {
                for (int l = 1; l < k+1&&j-l>=i-1; ++l) {
                    dp[i][j]=(dp[i][j]+dp[i-1][j-l])%mod;
                }
            }
        }
        return dp[n][target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.numRollsToTarget(30,30,500)<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}