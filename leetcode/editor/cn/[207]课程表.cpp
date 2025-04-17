#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int ans=0;
        for (const auto &item: nums){
            if (item%2==1)ans++;
        }
        return ans>=2;
    }
    static bool cmp(pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second)return a.first<b.first;
        return a.second>b.second;
    }
    int maximumLength(string str) {
        map<char,int> mp;
        bool find= false;
        for (const auto &item: str){
            mp[item]++;
            if(mp[item]>=3)find= true;
        }
        if(!find)return -1;
        vector<pair<char,int>>vec;
        for (const auto &item: mp){
            if(item.second>3) vec.emplace_back(item);
        }
        std::sort(vec.begin(), vec.end(), cmp);
        int ans=1;
        for (const auto &item: vec){
            char cur=item.first;
            for (int i = max(ans,2); i <= item.second-2; ++i) {
                if(i+2>item.second)break;
                string result(i, cur);
                if(findStr(str,result))ans= max(ans,i);
                else break;
            }
        }
        return ans;
    }
    bool findStr(string inputString,string targetSubstring ){
        int count = 0;
        size_t pos = 0;
        while ((pos = inputString.find(targetSubstring, pos)) != std::string::npos) {
            count++;
            pos ++;
        }
        if (count >= 3)return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    string str="aabcaabaaa";
    cout<<solution.maximumLength(str)<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}

