#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    set<int> q(nums.begin(), nums.end());
    vector<int> res(q.begin(), q.end());
    for (const auto &item: res) {
        cout << item << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    while (n--) {
        solve();
    }
    return 0;
}
