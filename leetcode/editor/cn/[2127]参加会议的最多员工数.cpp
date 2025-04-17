#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // in 统计每个节点的入度情况, max_length 统计每节点的最长链
        vector<int> in(n, 0);
        vector<int> max_length(n, 0);
        for (int x : favorite) in[x]++;
        deque<int> d;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) d.push_back(i);
        }
        // 拓扑排序
        while (!d.empty()) {
            int cur = d.front();
            d.pop_front();
            int ne = favorite[cur];
            max_length[ne] = max(max_length[ne], max_length[cur] + 1);
            if (--in[ne] == 0) d.push_back(ne);
        }
        // 圆桌最多放置一个大于 2 的环（ans1 统计最大值）
        // 圆桌可放置多个等于 2 的环（ans2 累加该长度）
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) continue;
            int j = favorite[i], cur = 1;
            while (j != i) {
                in[j] = 0;
                j = favorite[j];
                cur++;
            }
            if (cur == 2) ans2 += 2 + max_length[i] + max_length[favorite[i]];
            else ans1 = max(ans1, cur);
        }
        return max(ans1, ans2);
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