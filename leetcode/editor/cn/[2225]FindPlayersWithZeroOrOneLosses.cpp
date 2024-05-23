#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> win;
        set<int> los;
        set<int> one;
        for (const auto &item: matches){
            if(los.find(item[1])!=los.end()){
                one.erase(item[1]);
            }else{
                one.insert(item[1]);
                los.insert(item[1]);
                if(win.find(item[1])!=win.end()){
                    win.erase(item[1]);
                }
            }
            int a=item[0];
            if(los.find(a)==los.end()){
                win.insert(a);
            }
        }
        vector<int> frist,second;
        frist.assign(win.begin(), win.end());
        second.assign(one.begin(), one.end());
        return {frist,second};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout<<"h"<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}