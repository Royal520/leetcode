#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;
        for (auto c:s ) {
            if (c == '(') {
                l++; r++;
            } else if (c == ')') {
                l--; r--;
            } else {
                l--; r++;
            }
            l = max(l, 0);
            if (l > r) return false;
        }
        return l == 0;
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