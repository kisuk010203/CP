#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n, q; cin >> n >> q;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];
        vector<ll> suf_max(n);
        suf_max[n - 1] = max(a[n - 1], b[n - 1]);
        for (ll i = n - 2; i >= 0; i--) {
            suf_max[i] = max({a[i], b[i], suf_max[i + 1]});
        }
        vector<ll> suf_max_acc(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            suf_max_acc[i] = suf_max_acc[i - 1] + suf_max[i - 1];
        }
        while (q--) {
            ll l, r; cin >> l >> r;
            cout << suf_max_acc[r] - suf_max_acc[l - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
