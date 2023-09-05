#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encrypt(string& str,int n){
        for (int i = 0; i < str.size(); ++i) {
            char t=str[i];
            if(str[i]<'d'){
                str[i]=t+23;
            } else
                str[i]=t-3;
        }
        return str;
    }


};


int main() {
    Solution solution=*new Solution();
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<solution.encrypt(str,n)<<endl;
    return 0;
}
