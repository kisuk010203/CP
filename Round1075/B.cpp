#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define NEGINF -1000000000000L
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
        ll n, x; cin >> n >> x;
        vector<ll> a(n), b(n), c(n);
        for (ll i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
        ll sum_without_rb = 0L;
        for (ll i = 0; i < n; i++) {
            sum_without_rb += (b[i] - 1) * a[i];
        }
        if (sum_without_rb >= x) {
            cout << "0\n";
            continue;
        }
        ll max_with_rb = NEGINF;
        for (ll i = 0; i < n; i++) {
            max_with_rb = max(max_with_rb, a[i] * b[i] - c[i]);
        }
        if (max_with_rb <= 0) {
            cout << "-1\n";
            continue;
        }
        ll r = ceil((double)(x - sum_without_rb) / max_with_rb);
        cout << r << "\n";
    }   
    return 0;
}
