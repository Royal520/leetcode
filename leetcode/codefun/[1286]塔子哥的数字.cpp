#include<bits/stdc++.h>

using namespace std;
void solve() {
    long long n;
    int num;
    cin>>n>>num;
    string str=to_string(n);
    int len=str.size();
    long long res=n;
    if(num==9){
        res+= pow(10,len)*num;
    } else if(num==0){
        res*=10;
    }else{
        int i=0;
        for (i; i < str.size(); ++i) {
            if(str[i]-'0'<num){
                break;
            }
        }
        long long div=pow(10,len-i);
        long long last=res%div;
        long long pre=res/div*div*10;
        res=pre+num*div+last;
    }
    cout<<res<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    while (n--){
        solve();
    }
    return 0;
}