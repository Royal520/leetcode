#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;

    /*
     * 根据str获取ip,l:从序号开始，len：还要几个数字。
     */
    void dfs(string &pre, string &str, int start, int len) {
        int n = str.size();
        if (n - start < len||len*3<n-start)return;//长度不够
        if (start == str.size() && len == 0) {
            res.push_back(pre);
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if((i>1&&str[start]=='0')||(stoi(str.substr(start,i))>255)||(len-1)*3<n-start-i||start+i>n)continue; //如果有前导零，或者大于255,或者剩下长度长于len*3，或者超出str长度。
            if(start){
                pre.push_back('.');
            }
            pre=pre.append(str.substr(start, i));
            dfs(pre, str, start + i, len - 1);
            if(start)
                pre.pop_back();
            pre=pre.substr(0, pre.size() - i);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string pre;
        dfs(pre, s, 0, 4);
        return res;
    }

    int countTestedDevices(vector<int>& batteryPercentages) {
        int res=0;
        for (int i = 0; i < batteryPercentages.size(); ++i) {
            if(batteryPercentages[i]>0)res++;
            else continue;
            for (int j = i+1; j < batteryPercentages.size(); ++j) {
                batteryPercentages[j]= max(batteryPercentages[j]-1,0);
            }
        }
        return res;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for (int i = 0; i < variables.size(); ++i) {
            int a=variables[i][0];
            int b=variables[i][1];
            int c=variables[i][2];
            int d=variables[i][3];
            int t1=a;
            for (int j = 0; j < b-1; ++j) {
                t1=(t1*a)%10;
            }
            t1=t1%10;
            int t2=t1;
            for (int j = 0; j < c-1; ++j) {
                t2=(t2*t1)%d;
            }
            t2=t2%d;
            if(t2==target)res.push_back(i);
        }
        return res;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        int m=INT_MIN;
        int len=nums.size();
        for (const auto &item: nums){
            m= max(m,item);
        }
        long long res=0;
        int count=0;
        int L=0;
        int R=L;
        while (L<len){
            while (R<len&&count<k){
                if(nums[R]==m)count++;
                R++;
            }
            if((R==len&&R-L<k)||count<k)break;
            res+=len-R+1;
            if(nums[L]==m)count--;
            ++L;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout<<solution.countSubarrays(*new vector<int>({1,4,2,1,3}),3)<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}