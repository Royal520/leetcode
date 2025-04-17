#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPoints(string rings) {
        int ans=0;
        vector<vector<int>>dp(10,vector<int>(3));
        for (int i = 0; i < rings.size(); i=i+2) {
            int index=rings[i+1]-'0';
            char temp=rings[i];
            dp[index][getIndex(temp)]=1;
        }
        for (const auto &item: dp){
            int sum=0;
            for (const auto &yellow: item){
                sum+=yellow;
            }
            if(sum==3)++ans;
        }
        return ans;
    }
    int getIndex(char a){
        if(a=='R')return 0;
        if(a=='G')return 1;
        if(a=='B')return 2;
        return -1;
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