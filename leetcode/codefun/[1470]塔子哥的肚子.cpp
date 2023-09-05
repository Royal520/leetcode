#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n;
    cin>>n;
    long long mod=1000000007;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
    }
    int m= std::accumulate(f.begin(), f.end(),0);
    vector<vector<long long>> dp(n,vector<long long>(m+1));
    for (int i = 1; i <=min(300,m) ; ++i) {
        dp[0][i]=1;
    }
    dp[0][f[0]]=0;
    for (int i = 1; i < n; ++i) {
        int start=i+1;
        int end= min((i+1)*300,m-(n-1-i));
        if(f[i]==1)dp[i][start]=0;
        else dp[i][start]=dp[i-1][start-1];
        for (int j = start+1; j <=end; ++j) {
            long long temp=0;
            for (int k = i; k <j ; ++k) {
                if(f[i]!=j-k)
                    temp+=dp[i-1][k]%mod;
            }
            dp[i][j]=temp%mod;
        }
    }
    cout<<dp[n-1][m]%mod<<endl;
}


int main() {
    solve();
    return 0;
}