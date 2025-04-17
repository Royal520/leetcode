#include<bits/stdc++.h>
#include "util/ListNode.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res=-1;
        for (int i = 0; i < nums.size()-1; ++i) {
            int temp=-1;
            for (int j = i+1; j < nums.size(); ++j) {
                if(temp==-1){
                    if(nums[j]-nums[j-1]==1)
                        temp=2;
                } else{
                    int sub=nums[j]-nums[j-1];
                    int flag=temp%2==0?-1:1;
                    if(sub== flag){
                        temp++;
                    } else{
                        res=max(temp,res);
                        temp=-1;
                        break;
                    }
                    res=max(temp,res);
                }
                res= max(temp,res);
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