//
// Created by gl on 2023/8/18.
//
#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getMaxDis(vector<int>& nums,int n,int k){
        int res=0;
        map<int,int>mp;
        int right=0;
        int count=0;
        for (int i = 0; i < n&&right<n; ++i) {
            while (mp.size()<=k&&right<n){
                mp[nums[right]]++;
                ++right;
                ++count;
            }
            if(mp.size()<=k){
                res= max(res,count);
            } else{
                --count;
                if(mp[nums[i]]==1)
                    mp.erase(nums[i]);
                else mp[nums[i]]--;
                res= max(res,count);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution=*new Solution();
    int n,k;
    cin>>n>>k;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        int j;
        cin>>f[i];
    }
    cout<<solution.getMaxDis(f,n,k)<<endl;
    return 0;
}