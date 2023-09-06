//
// Created by gl on 2023/8/18.
//
#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minPalindromeStr(string str){
       int i=0;
       int j=str.size()-1;
       int k=2;
        while (i<j){
            if(str[i]!=str[j]){
                if(str[i]<str[j]){
                    str[j]=str[i];
                    --k;
                } else{
                    str[i]=str[j];
                    --k;
                }
            }
            ++i;
            --j;
        }
        i=0;
        j=str.size()-1;
        while (k>0&&i<=j){
            if(str[i]!='a'){
                if(i<j&&k==2){
                    str[i]='a';
                    str[j]='a';
                    break;
                } else{
                    str[i]='a';
                }
            } else{
                ++i;
                --j;
            }
        }
        return str;
   }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution=*new Solution();
    string str;
    cin>>str;
    cout<<solution.minPalindromeStr(str)<<endl;
    return 0;
}