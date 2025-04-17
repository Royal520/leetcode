#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference) {
        int mn, mx;
        for (int j = indexDifference; j < nums.size(); ++j) {
            int i = j - indexDifference;
            if (nums[i] > nums[mx]) {
                mx = j - indexDifference;
            } else if (nums[i] < nums[mn]) {
                mn = j - indexDifference;
            }
            if (nums[j] - nums[mn] >= valueDifference) {
                return {mn, j};
            }
            if (nums[mx] - nums[j] >= valueDifference) {
                return {mx, j};
            }
        }
        return {-1, -1};
    }
    int sumCounts(vector<int> &nums) {
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < nums.size(); i++) {
            set<int> q;
            for (int j = i; j < nums.size(); j++) {
                q.insert(nums[j]);
                ans = (ans + q.size() * q.size()) % mod;
            }
        }
        return ans;
    }

    int minChanges(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i = i + 2) {
            if (s[i] != s[i + 1]) ans++;
        }
        return ans;
    }

    int lengthOfLongestSubsequence(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        stack<int> q;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum > target) {
                if (q.empty()) return -1;
                else {
                    int top = q.top();
                    q.pop();
                    sum -= top;
                }
            }
            q.push(nums[i]);
            if (sum == target) return q.size();
        }
        return -1;
    }
    int findKOr(vector<int> &nums, int k) {
        int ans = 0;
        if (k == nums.size()) {
            int temp = nums[0];
            for (const auto &item: nums) {
                temp &= item;
            }
            return temp;
        } else if (k == 1) {
            int temp = nums[0];
            for (const auto &item: nums) {
                temp |= item;
            }
            return temp;
        }
        std::sort(nums.begin(), nums.end());
        ans = 0;
        for (int i = 0; pow(2, i) < nums.back(); ++i) {
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if ((1 << i & nums[j]) == (1 << i)) count++;
            }
            if (count >= k) ans += pow(2,i);
        }
        return ans;
    }

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long c1=0,t1=0;
        long long c2=0,t2=0;
        for (const auto &item: nums1){
            if(item==0)++t1;
            else c1+=item;
        }
        for (const auto &item: nums2){
            if(item==0)++t2;
            else c2+=item;
        }
        long long mi1=c1+t1;
        long long ma1=t1==0?c1:INT64_MAX;
        long long mi2=c2+t2;
        long long ma2=t2==0?c2:INT64_MAX;
        if(mi1>ma2|mi2>ma1)return -1;
        return max(mi1,mi2);
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
            long long ans=0;
            for (int i = 0; i < nums.size()-2; ++i) {
                int mai=i;
                for (int j = i+1; j<i+3; ++j) {
                    if(nums[j]>=nums[mai])mai=j;
                }
                int add=k-nums[mai];
                if(add){
                    ans+=add;
                    nums[i]+=add;
                    if(i+1<nums.size())nums[i+1]+=add;
                    if(i+2<nums.size())nums[i+2]+=add;
                }
            }
            return ans;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout << solution.minIncrementOperations(*new vector<int>({0,1,3,3}), 5) << endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}