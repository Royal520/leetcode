//
// Created by gl on 2023/8/21.
//
#include<bits/stdc++.h>
using namespace std;
static void solve(){
    int m,n;
    cin>>m;
    cin>>n;
    int res=n%m==0?m:n%m;
    cout<<res<<endl;
}


int main() {
    clock_t start,end;
    int n;
    cin>>n;
    while (n-->0){
        solve();
    }
    return 0;
}



