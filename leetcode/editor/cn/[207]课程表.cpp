#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> indeg;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &item: prerequisites) {
            indeg[item[1]]++;
            edges[item[0]].push_back(item[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0)q.push(i);
        }
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int front = q.front();
            q.pop();
            for (const auto &item: edges[front]) {
                indeg[item]--;
                if (indeg[item] == 0)q.push(item);
            }
        }
        return visited == numCourses;
    }

    int numberOfPoints(vector<vector<int>> &nums) {
        set<int> q;
        for (const auto &item: nums) {
            for (int i = item.front(); i <= item.back(); ++i) {
                q.insert(i);
            }
        }
        return q.size();
    }

    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minT = 0;
        minT = max(abs(fx - sx), abs(fy - sy));
        if (minT == 0 && t == 1)return false;
        return minT <= t;
    }

    int minimumMoves(vector<vector<int>> &grid) {

    }

    void dfs(vector<vector<int>> &grid) {

    }

    bool inArea(int i, int j, vector<vector<int>> &grid) {
        return i >= 0 & i < grid.size() && j >= 0 && j < grid[0].size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout << solution.isReachableAtTime(1, 4, 1, 3, 1) << endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}