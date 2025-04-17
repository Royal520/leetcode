#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (const auto &item: words){
            int left=-1;
            int len=0;
            for (int i=0;i<item.length();i++){
                if(item[i]==separator){
                    if(len!=0)
                        res.push_back(item.substr(left,len));
                    len=0;
                    left=-1;
                }else{
                    ++len;
                    if(left==-1){
                        left=i;
                    }
                }
            }
            if(len!=0)
                res.push_back(item.substr(left,len));
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.splitWordsBySeparator(*new vector<string >{"$easy$","$problem$"},'$').size()<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}