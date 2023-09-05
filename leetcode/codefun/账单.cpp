#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n,m;
    cin >> n>>m;
    vector<long long>res(m+1,0);
    while (n--){
        long long a,b;
        cin>>a>>b;
        long long pay=(b+a-1)/a;
        for (long long i = 1; i < a; ++i) {
            long long index;
            cin>>index;
            res[index]+=pay;
        }
    }
    for (long long i = 1; i <m+1 ; ++i) {
        cout<<res[i]<<" ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}