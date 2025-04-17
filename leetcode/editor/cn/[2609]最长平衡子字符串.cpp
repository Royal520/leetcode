#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans=0;
        int i=0;
        while (s[i]=='1')i++;
        s=s.substr(i,s.size()-i);
        int j=s.size()-1;
        while (s[j]=='0')j--;
        s=s.substr(0,j+1);
        int L=0,R=0;
        bool start= true;
        for (int i = 0; i < s.size(); ++i) {
            if(start){
                if(s[i]=='0')L++;
                else{
                    start= false;
                    R++;
                }
            }else{
                if(s[i]=='1')R++;
                else{
                    start= true;
                    ans= max(ans,2*(min(L,R)));
                    L=1;
                    R=0;
                }
            }
        }
        if(!start){
            ans= max(ans,2*(min(L,R)));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.findTheLongestBalancedSubstring("111")<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}