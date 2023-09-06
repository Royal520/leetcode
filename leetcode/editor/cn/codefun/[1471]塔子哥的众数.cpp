#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int>nums(n);
    long long sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
        sum+=nums[i];
    }
    long long most=sum/n;
    int small=0;long long countSmall=0;
    int big=0;long long countBig=0;
    int tempsmall=0;long long tempcountSmall=0;
    int tempbig=0;long long tempcountBig=0;
    for (const auto &item: nums){
        if(item<most){
            ++small;
            countSmall+=item;
        } else if(item>most){
            ++big;
            countBig+=item;
        }
        if(most%2==1){
            if(item<most+1){
                ++tempsmall;
                tempcountSmall+=tempsmall;
            } else if(item>most+1){
                ++tempbig;
                tempcountBig+=tempbig;
            }
        }
    }
    if(most%2==1)
        cout<<small*most-countSmall<<endl;
    else{
        long long minM=min((small*most-countSmall),countBig-big*most);
        long long minTemp=min(tempsmall*(most+1)-tempcountSmall,tempcountBig-tempbig*(most+1));
        cout<<min(minM,minTemp)<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<INT64_MAX<<endl;

    solve();
    return 0;
}