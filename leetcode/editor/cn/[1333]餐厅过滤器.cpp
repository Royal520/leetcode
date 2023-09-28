#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return (a.second==b.second&&a.first>b.first)||(a.second>b.second);
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> res;
        for (const auto &item: restaurants){
            if(veganFriendly){
                if(item[2]&&item[3]<=maxPrice&&item[4]<=maxDistance){
                    res.emplace_back(item[0],item[1]);
                }
            }else{
                if(item[3]<=maxPrice&&item[4]<=maxDistance){
                    res.emplace_back(item[0],item[1]);
                }
            }
        }
        std::sort(res.begin(), res.end(),cmp);
        vector<int> ans;
        for (const auto &item: res){
            ans.push_back(item.first);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout<<<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}