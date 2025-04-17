#include<bits/stdc++.h>
#include "util/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumLevels(vector<int> &possible) {
        int n = possible.size();
        int tot = accumulate(possible.begin(), possible.end(), 0) * 2 - n;
        int pre = 0;
        for (int i = 0; i < n - 1; i++) {
            pre += possible[i] == 1 ? 1 : -1;
            if (2 * pre > tot) { return i + 1; }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout << solution.minimumLevels(*new vector<int>({0, 1, 0})) << endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}