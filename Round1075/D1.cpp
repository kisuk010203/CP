#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007L
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
        ll n, c;
        cin >> n >> c;
        vector<bool> w(n);
        string s; cin >> s;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1') w[i] = true;
            else w[i] = false;
        }
        ll res = 1L;
        if (!w[0] || !w[n - 1]) {
            cout << "-1\n";
            continue;
        }
        // putting 1
        res *= 2;
        c /= gcd(c, 2LL);
        for (ll i = 2; i <= n - 1; i++) {
            
            if (w[i - 1]) {
                res *= 2;
                res %= MOD;
                c /= gcd(c, 2LL);
            } else {
                res *= (i - 1);
                res %= MOD;
                c /= gcd(c, i - 1);
            }
            if (c == 1) {
                res = 0;
                break;
            }
        }
        if (res == 0) cout << "-1\n";
        else cout << res % MOD << "\n";
    }
    return 0;
}
