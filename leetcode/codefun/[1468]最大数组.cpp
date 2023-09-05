//
// Created by gl on 2023/8/21.
//
#include<bits/stdc++.h>
using namespace std;
static void solve(){
    int n;
    cin>>n;
    vector<long long> f(n);
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
    }
    long long res=0;
    if(n==1){
        cout<<f[0]<<endl;
        return;
    }
    long long sum=0;
    long long maxM=0;
    for (int i = 0; i < n; ++i) {
        res+=f[i];
        if(i<n-1){
            long long temp=f[i]*f[i+1]-f[i]-f[i+1];
            maxM= max(temp,maxM);
        }
    }
    cout<<res+maxM<<endl;
}


int main() {
    solve();
    return 0;
}
