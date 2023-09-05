#include<bits/stdc++.h>

using namespace std;

static void solve() {
    string str;
    cin >> str;
    vector<vector<int>> f(str.size(),vector<int>(2));

    long long res=0;
    for (int i = 0; i < str.size(); ++i) {
        if(str[i]=='0'){
            f[i][0]=0;
            f[i][1]=1;
        } else{
            f[i][0]=1;
            f[i][1]=0;
        }
        for (int j = i+1; j <str.size() ; ++j) {
            if(str[j]=='0'){
                f[j][0]=f[j-1][1];
                f[j][1]=f[j-1][0]+1;
            } else{
                f[j][0]=f[j-1][1]+1;
                f[j][1]=f[j-1][0];
            }
            res+= min(f[j][0],f[j][1]);
        }
    }
    cout<<res;
}


int main() {
    solve();
    return 0;
}