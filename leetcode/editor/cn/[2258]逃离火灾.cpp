#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n, m;
    bool ok;
    vector<vector<int>> g, fg, pg;
    int maximumMinutes(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(); m = g[0].size();
        fg = vector<vector<int>>(n, vector<int>(m, 0)), pg = vector<vector<int>>(n, vector<int>(m, 0));
        if (!check(0)) return -1;
        int l = 0, r = n * m;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return r == n * m ? (int)1e9 : r;
    }
    bool check(int t) {
        ok = false;
        deque<vector<int>> frie;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fg[i][j] = pg[i][j] = 0;
                if (g[i][j] == 1) {
                    fg[i][j] = 1;
                    frie.push_back({i, j});
                }
            }
        }
        while (t-- > 0) update(frie, true, 0);
        if (fg[0][0] != 0) return false;
        deque<vector<int>> people;
        pg[0][0] = 1;
        people.push_back({0, 0});
        while (!people.empty()) {
            update(frie, true, 1);
            update(people, false, 1);
            if (ok) return true;
        }
        return false;
    }
    void update(deque<vector<int>>& deque, bool isFire, int offset) {
        int sz = deque.size();
        while (sz-- > 0) {
            vector<int> info = deque.front();
            deque.pop_front();
            int x = info[0], y = info[1];
            for (vector<int> dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[nx][ny] == 2) continue;
                if (isFire) {
                    if (fg[nx][ny] != 0) continue;
                    fg[nx][ny] = fg[x][y] + offset;
                } else {
                    if (nx == n - 1 && ny == m - 1 && (fg[nx][ny] == 0 || fg[nx][ny] == pg[x][y] + offset)) ok = true;
                    if (fg[nx][ny] != 0 || pg[nx][ny] != 0) continue;
                    pg[nx][ny] = pg[x][y] + offset;
                }
                deque.push_back({nx, ny});
            }
        }
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