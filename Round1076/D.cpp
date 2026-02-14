#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> strength(n), hp(n);
        vector<ll> acc(n, 0);
        for (ll i = 0; i < n; i++) cin >> strength[i];
        for (ll i = 0; i < n; i++) cin >> hp[i];
        acc[0] = hp[0];
        for (ll i = 1; i < n; i++) {
            acc[i] = acc[i - 1] + hp[i];
        }
        sort(strength.begin(), strength.end());
        ll score = 0;
        for (ll i = 0; i < n; i++) {
            ll x = strength[i];
            ll swords = n - i;
            ll idx = upper_bound(acc.begin(), acc.end(), swords) - acc.begin();
            score = max(score, x * idx);
        }
        cout << score << "\n";

    }
    return 0;
}
