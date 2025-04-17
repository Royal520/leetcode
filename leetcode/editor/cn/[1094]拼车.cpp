#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool static cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), cmp);
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };

        // 创建降序的小根堆，并传入比较函数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        for (const auto &item: trips){
            int dis=item[1];
            while (!minHeap.empty()&&minHeap.top().first<=dis){
                auto cur=minHeap.top();
                capacity+=cur.second;
                minHeap.pop();
            }
            minHeap.emplace(item[2],item[0]);
            capacity-=item[0];
            if(capacity<0)return false;
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();

    cout <<solution.carPooling(*new vector<vector<int>>{{3,2,7},{3,7,9},{8,3,9}},11)<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}