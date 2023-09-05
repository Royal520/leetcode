#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;

    /*
     * 根据str获取ip,l:从序号开始，len：还要几个数字。
     */
    void dfs(string &pre, string &str, int start, int len) {
        int n = str.size();
        if (n - start < len||len*3<n-start)return;//长度不够
        if (start == str.size() && len == 0) {
            res.push_back(pre);
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if((i>1&&str[start]=='0')||(stoi(str.substr(start,i))>255)||(len-1)*3<n-start-i||start+i>n)continue; //如果有前导零，或者大于255,或者剩下长度长于len*3，或者超出str长度。
            if(start){
                pre.push_back('.');
            }
            pre=pre.append(str.substr(start, i));
            dfs(pre, str, start + i, len - 1);
            if(start)
                pre.pop_back();
            pre=pre.substr(0, pre.size() - i);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string pre;
        dfs(pre, s, 0, 4);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout<<solution.restoreIpAddresses("101023").size()<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}