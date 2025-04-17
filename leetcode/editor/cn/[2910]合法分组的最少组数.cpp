#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(pair<int, int>a, pair<int, int>b){
        return a.second==b.second?a.first<b.first:a.second<b.second;
    }

    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (const auto &item: nums){
            mp[item]++;
        }
        vector<int> num;
        for (const auto &item: mp){
            num.push_back(item.second);
        }
        std::sort(num.begin(), num.end());
        int mn=num[0];
        while (mn>0){
            int ret=0;
            for (const auto &item: num){
                if(item/mn<item%mn){
                    ret=0;
                    break;
                }
                ret+=(item+mn)/(mn+1);
            }
            if(ret){
                return ret;
            }
            --mn;
        }

        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.minGroupsForValidAssignment(*new vector<int>({1,1,3,3,1,1,2,2,3,1,3,2}))<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}