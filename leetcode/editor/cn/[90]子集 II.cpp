#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * 回溯当下一个数和上一个数相同就跳过
     */
    vector<vector<int>> subsetsWithDup(vector<int> &num) {
        std::sort(num.begin(), num.end());
        vector<int> cur;
        vector<vector<int>> f;
        f.emplace_back();
        function<void(vector<int> &, int)> dfs = [&](vector<int> &cur, int i) {
            if (i >= num.size())return;
            cur.push_back(num[i]);
            f.push_back(cur);
            dfs(cur, i + 1);
            cur.pop_back();
            while (i < num.size() - 1 && num[i + 1] == num[i]) {
                ++i;
            }
            if (i < num.size() - 1) {
                dfs(cur, i + 1);
            }
        };
        dfs(cur, 0);
        return f;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout << solution.subsetsWithDup(*new vector<int>({5, 5, 5, 5, 5})).size() << endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}