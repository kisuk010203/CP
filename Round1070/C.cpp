#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> evens;
        ll max_odd = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2 == 0)
                evens.push_back(v[i]);
            else
                max_odd = max(max_odd, v[i]);
        }
        if (max_odd == 0) {
            for (int i = 0; i < n; i++)
                cout << 0 << " ";
            cout << "\n";
            continue;
        }
        sort(evens.begin(), evens.end(), greater<ll>());
        vector<ll> ans_dp(n + 1);
        int odd_cnt = n - evens.size();
        ans_dp[0] = 0;
        ans_dp[1] = max_odd;
        for (int i = 2; i <= n; i++) {
            if (i - 1 <= evens.size()) {
                ans_dp[i] = ans_dp[i - 1] + evens[i - 2];
            } else {
                ans_dp[i] = ans_dp[i - 2];
            }
        }
        if (odd_cnt % 2 == 0)
            ans_dp[n] = 0;
        for (int i = 0; i < n; i++)
            cout << ans_dp[i + 1] << " ";
        cout << "\n";
    }
    return 0;
}
