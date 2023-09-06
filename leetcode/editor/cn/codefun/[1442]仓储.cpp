#include<bits/stdc++.h>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<long long>dis(n+1);
    long long sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
        sum+=nums[i];
        dis[i+1]=dis[i]+nums[i];
    }
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a==b) return 0;
    else{
        long long res= dis[b-1]-dis[a-1];
        res= min(res,sum-res);
        return res;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<solve();
    return 0;
}