#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string isClose(map<int,int>mp,int a,int b){
        if(abs(mp[a]-mp[b])==1)return "Yes";
        return "No";
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution=*new Solution();
    clock_t start,end;
    int n;
    cin>>n;
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        int j;
        cin>>j;
        mp[j]=i;
    }
    int a,b;
    cin>>a>>b;
    cout<<solution.isClose(mp,a,b)<<endl;
    start=clock();
    end=clock();
    cout<<"spend "<<double(end-start)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    return 0;
}


