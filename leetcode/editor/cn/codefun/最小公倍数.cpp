#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a;
    int b;
    cin >> a >> b;
    if (a > b)swap(a, b);
    int res;
    for (int i = 1; i <= a; ++i) {
        res = b * i;
        if (res % a == 0) {
            cout << res;
            break;
        }
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
