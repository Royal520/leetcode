#include<bits/stdc++.h>

using namespace std;

static void solve() {
    int n,k;
    cin >> n>>k;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long mod=1000000007;
    std::sort(nums.begin(), nums.end());
    long long res=0;
    for (const auto &item: nums){
        res=(res+item)%mod;
    }
    if(k>=n)k=n-1;
    for (int i = n-1; i >0&&k>0; --i) {
/*        long long mut=(nums[i-1]*nums[i]+1)%mod;
        long long add=(nums[i-1]+nums[i])%mod;
        long long temp=mut-add;*/
        long long temp=((nums[i-1]-1)*nums[i]-nums[i-1]+1)%mod;
        nums[i-1]=(nums[i-1]*nums[i])%mod;
        nums[i]=1;
        res=(res+temp)%mod;
        --k;
    }
    cout<<res<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}