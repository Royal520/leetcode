#include<bits/stdc++.h>

using namespace std;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10, MOD = 1e9 + 7;

int n;
int w[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    ll t = 0;
    for (int i = 1, j = n; i <= n; i++, j--)
        t = (t + 1ll * j * w[i]) % MOD;
    ll ans = 0;
    for (int i = 1, j = n; i <= n; i++, j--) {
        ans = (ans + 1ll * i * t) % MOD;
        t = ((t - 1ll * j * w[i]) % MOD + MOD) % MOD;
    }
    cout << ans << endl;
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
