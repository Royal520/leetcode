#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigits(int num) {
        int ans=0;
        string str=to_string(num);
        vector<int>dp(10);
        for(auto item:str){
            dp[item-'0']++;
        }
        for (int i = 1; i < 10; ++i) {
            if(dp[i]&&num%i==0)ans+=dp[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.countDigits(1248)<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}