#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007L
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        // TODO
        ll n, c;
        cin >> n >> c;
        vector<int> w(n);
        string s;
        cin >> s;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1')
                w[i] = 1;
            else if (s[i] == '?')
                w[i] = 2;
            else
                w[i] = 0;
        }
        if (w[0] == 2) w[0] = 1;
        if (w[n - 1] == 2) w[n - 1] = 1;
        ll res = 1L;
        if ((w[0] == 0) || (w[n - 1] == 0)) {
            cout << "-1\n";
            continue;
        }
        vector<int> remain;
        // putting 1
        res *= 2;
        c /= gcd(c, 2LL);
        for (ll i = 2; i <= n - 1; i++) {

            if (w[i - 1] == 1) {
                res *= 2;
                res %= MOD;
                c /= gcd(c, 2LL);
            } else if (w[i - 1] == 0) {
                res *= (i - 1);
                res %= MOD;
                c /= gcd(c, i - 1);
            }
            else {
                if (i % 2 == 1) {
                    res *= 2;
                    res %= MOD;
                    c /= gcd(c, 2LL);
                } else {
                    if (i == 2) continue;
                    remain.push_back(i);
                }
            }
            if (c == 1) {
                res = 0;
                break;
            }
        }
        if (res == 0)
            cout << "-1\n";
        else if (remain.empty()) {
            if (c != 1)
                cout << res % MOD << "\n";
            else
                cout << "-1\n";
        }
        else {
            // cout << "Reached here, current res : " << res % MOD << "\nRemain : ";
            // for (auto i : remain) {
            //     cout << i << " ";
            // }
            // cout << "\n";
            // remain non-empty
            if ((c & (c - 1)) != 0) {
                for (auto i : remain) {
                    res *= 2;
                    res %= MOD;
                    c /= gcd(c, 2LL);
                    if (c == 1) break;
                }
                if (c != 1)
                    cout << res % MOD << "\n";
                else
                    cout << "-1\n";
            }
            else {
                // c is power of 2
                int e = log2(c);
                reverse(remain.begin(), remain.end());
                for (auto i : remain) {
                    if (e > 1) {
                        res *= 2;
                        res %= MOD;
                        c /= 2;
                        e--;
                    }
                    else {
                        res *= (i - 1);
                        res %= MOD;
                    }
                }
                if (c != 1)
                    cout << res % MOD << "\n";
                else
                    cout << "-1\n";
            }
        }
    }
    return 0;
}
