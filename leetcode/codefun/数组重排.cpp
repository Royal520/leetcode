#include<bits/stdc++.h>

using namespace std;

static void solve() {
    int n,m;
    cin >> n>>m;
    vector<int> f1(n);
    vector<int> f2(n);
    for (int i = 0; i < n; ++i) {
        cin >> f1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f2[i];
    }
    std::sort(f1.begin(), f1.end());
    std::sort(f2.begin(), f2.end());
    string res="Yes";
    for (int i = 0,j=n-1; i < n; ++i,--j) {
        if(f1[i]+f2[j]>m||(f1[i]+f2[j]<1)){
            res="No";
            break;
        }
    }
    cout<<res<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=1;
    while (n--){
        solve();
    }
    return 0;
}