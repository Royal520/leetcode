#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> res;
    vector<int> indeg;
    vector<vector<int>> edges;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &cur: prerequisites) {
            indeg[cur[0]]++;
            edges[cur[1]].push_back(cur[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int visited=0;
        while (!q.empty()) {
            ++visited;
            int front = q.front();
            q.pop();
            res.push_back(front);
            for (const auto &item: edges[front]){
                indeg[item]--;
                if(indeg[item]==0)q.push(item);
            }
        }
        if(visited!=numCourses)return {};
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout<<solution.findOrder(3,*new vector<vector<int>>({{1,0},{1,2},{0,1}})).size()<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}