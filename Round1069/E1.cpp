#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fast_exp(ll base, ll exp, ll mod) {
    ll res = 1L;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }   
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        ll n, m, p;
        cin >> n >> m >> p;
        vector<ll> mult_inv(n * 2, 1);
        ll inv = fast_exp(m, p - 2, p);
        for (ll i = 1; i < n * 2; i++) {
            mult_inv[i] = (mult_inv[i - 1] * inv) % p;
        }

        ll ans = 0L;
        ll res = 0L;
        // single 
        for (int len = 1; len <= n; len++) {
            ll ways = (n - len + 1);
            ll add = (ways * mult_inv[len / 2]) % p;
            ans += add;
            ans %= p;
            res += ways;
            res %= p;
        }
        // pairs
        // by len1, len2
        for (int len1 = 1; len1 <= n; len1++) {
            for (int len2 = 1; len2 <= n; len2++) {
                ll total_ways = (n - len1 + 1) * (n - len2 + 1);
                total_ways %= p;
                if (len1 == len2) 
                    total_ways = (total_ways + p - (n - len1 + 1)) % p;
                res += total_ways;
                res %= p;
                ll same_center_ways;
                if ((len1 + len2) % 2 == 1 || len1 == len2) {
                    same_center_ways = 0L;
                } else {
                    same_center_ways = (n - max(len1, len2) + 1);
                }
                ll diff_center_ways = (total_ways + p - same_center_ways) % p;
                ll add_same_center = (same_center_ways * mult_inv[max(len1, len2) / 2]) % p;
                ll add_diff_center = (diff_center_ways * mult_inv[len1 / 2 + len2 / 2]) % p;
                ans = (ans + add_same_center + add_diff_center) % p;
            }
        }
        cout << ans % p << "\n";
        ll real_res = (n * (n + 1L) / 2L) % p;
        real_res = (real_res * real_res) % p;
        assert(res == real_res);
    }
    return 0;
}
