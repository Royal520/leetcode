#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> res;
    vector<int> indeg;
    vector<vector<int>> edges;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &cur: prerequisites) {
            indeg[cur[0]]++;
            edges[cur[1]].push_back(cur[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int visited=0;
        while (!q.empty()) {
            ++visited;
            int front = q.front();
            q.pop();
            res.push_back(front);
            for (const auto &item: edges[front]){
                indeg[item]--;
                if(indeg[item]==0)q.push(item);
            }
        }
        if(visited!=numCourses)return {};
        return res;
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> nums(n*n+1,0);
        int a=-1;
        int b=-1;
        int sum=0;
        for (const auto &item: grid){
            for (const auto &i: item){
                sum+=i;
                nums[i]++;
            }
        }
        int len=n*n+1;
        for (int i = 1; i < len; ++i) {
            if(nums[i]==2)a=i;
            else if(nums[i]==0)b=i;
        }
        return {a,b};
    }

    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i=i+3) {
            if(nums[i+2]-nums[i]>k)return {};
            else res.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return res;
    }

    long long minimumCost(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mi=INT_MAX;
        int ma=INT_MIN;
        for (const auto &item: nums){
            mp[item]++;
            mi= min(mi,item);
            ma= max(ma,item);
        }
        int n=nums.size();
        int a=0,b=0,c=0;
        std::sort(nums.begin(), nums.end());
        long long ans=0;
        vector<int> pal=generatePalindromes(mi,ma);
        int frist=pal.front();
        c=countElementsGreaterThan(nums,frist);
        b=mp[frist];
        a=n-b-c;
        for (const auto &item: nums){
            ans+= abs(item-frist);
        }
        int pre=ans;
        for (int i = 1; i < pal.size(); ++i) {
            int c1=countElementsGreaterThan(nums,pal[i]);
            int b1=mp[pal[i]];
            int a1=n-c1-b1;
            int dis=pal[i]-pal[i-1];
            int temp=pre-c1*dis-(c-c1)+a*dis+;
        }
    }

    int countElementsGreaterThan(std::vector<int>& numbers, int i) {
        auto it = std::lower_bound(numbers.begin(), numbers.end(), i);
        return distance(it, numbers.end());
    }
    vector<int> generatePalindromes(int mi,int ma){
        vector<int> res;
        for (int i = mi; i < min(10,ma); ++i) {
            res.push_back(i);
        }
        for (int i = 1; i < 10; ++i) {
            int cur=i*10+i;
            if(cur>=mi&&cur<=ma)res.push_back(cur);
            for (int j = 0; j < 10; ++j) {
                int temp=i*10;
                temp=(temp+j)*10+i;
                if(temp>=mi&&temp<=ma)res.push_back(temp);
            }
        }
        for (int i = 10; i < 100; ++i) {
            int a=i/10;
            int b=i%10;
            int cur=(i*10+b)*10+a;
            if(cur>=mi&&cur<=ma)res.push_back(cur);
            for (int j = 0; j < 10; ++j) {
                int temp=i*10;
                temp=((temp+j)*10+b)*10+a;
                if(temp>=mi&&temp<=ma)res.push_back(temp);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    solution.generatePalindromes(2,100);
    cout<<""<<endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}