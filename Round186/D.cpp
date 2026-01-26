#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    ll fact[51];
    fact[0] = 1;
    for (ll i = 1; i <= 50; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    ll perm[51][51];
    for (ll n = 0; n <= 50; n++) perm[n][0] = 1;
    for (ll n = 1; n <= 50; n++) {
        for (ll r = 1; r <= n; r++) {
            perm[n][r] = perm[n - 1][r - 1] * n;
            perm[n][r] %= MOD;
        }
    }
    while (T--) {
        int n; cin >> n;
        vector<ll> v(n + 1);
        for (int i = 0; i < n + 1; i++) cin >> v[i];
        ll sum = 0;
        for (int i = 0; i < n + 1; i++) sum += v[i];
        ll q = sum / n;
        ll r = sum % n;

        ll hell_over_cnt = 0;
        ll mid_over_cnt = 0;
        for (int i = 1; i < n + 1; i++) {
            if (v[i] > q + 1) hell_over_cnt++;
            else if (v[i] == q + 1) mid_over_cnt++;
        }

        if (hell_over_cnt > 0 || mid_over_cnt > r) {
            cout << "0\n";
            continue;
        }
        ll ans = perm[r][mid_over_cnt] * fact[n - mid_over_cnt];
        ans %= MOD;
        cout << ans << "\n";

        
    }
    return 0;
}
