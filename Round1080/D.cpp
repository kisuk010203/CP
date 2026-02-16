#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> f(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        vector<ll> sm2a(n + 1);
        for (int i = 1; i < n; i++) {
            sm2a[i] = f[i] - f[i + 1];
        }
        vector<ll> ans(n + 1);
        for (int i = 2; i <= n - 1; i++) {
            ans[i] = (sm2a[i - 1] - sm2a[i]) / 2;
        }
        ll an = f[1];
        for (int i = 2; i <= n; i++) {
            an -= (ans[i] * (i - 1));
        }
        ans[n] = an / (n - 1);
        ll a1 = f[n];
        for (int i = n - 1; i >= 2; i--) {
            a1 -= (ans[i] * (n - i));
        }
        ans[1] = a1 / (n - 1);
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
