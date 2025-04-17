#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    set<char> q={'a','e','i','o','u'};
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for (int i = left; i <right+1 ; ++i) {
            if(match(words[i]))++ans;
        }
        return ans;
    }
    bool match(string& str){
        if(q.count(str[0])>0&&q.count(str.back())>0)return true;
        return false;
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