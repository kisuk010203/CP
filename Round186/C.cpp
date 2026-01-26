#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        // TODO
        ll n; cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];
        for (ll i = 0; i < n; i++) cin >> c[i];
        ll possible_i = 0;
        ll possible_k = 0;
        for (ll i = 0; i < n; i++) {
            bool possible = true;
            for (ll jj = 0, j = i; j < n + i; j++, jj++) {
                ll idx = j % n;
                // cout << "Comparing a[" << i << "] = " << a[i] << " with b[" << idx << "] = " << b[idx] << "\n";
                if (a[jj] >= b[idx]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                // cout << "Possible at i = " << i << "\n";
                possible_i++;
            }
        }
        for (ll i = 0; i < n; i++) {
            bool possible = true;
            for (ll jj = 0, j = i; j < n + i; j++, jj++) {
                ll idx = j % n;
                if (c[jj] <= b[idx]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                possible_k++;
            }
        }
        ll ans;
        ans = possible_i * possible_k * n;
        // cout << possible_i << " " << possible_k << " " << n << "\n";
        cout << ans << "\n";
    }
    return 0;
}
