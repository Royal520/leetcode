#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long a,b,count;
    cin >> a>>b>>count;
    int ans=0;
    int day=1;
    while (count>0){
        if(day==1){
            count=count-a-b;
            ans++;
            day++;
        } else{
            count-=a;
            ++ans;
            day=(day==2)?3:1;
        }
    }
    cout<<ans<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}