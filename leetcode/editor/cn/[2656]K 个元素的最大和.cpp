#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxNum=*max_element(nums.begin(), nums.end());
        int ans=(maxNum+maxNum+k-1)*k/2;
        return ans;
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