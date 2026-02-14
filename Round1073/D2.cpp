#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        ll dp[n + 10][n + 10][n + 10][4];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;
        dp[0][1][(s[0] == '(' ? 1 : -1)][0] = 1;
        for (int last = 1; last < n; last++) {
            for (int len = 0; len <= last; len++) {
                for (int bal = 0; bal <= last; bal++) {
                    for (int state = 0; state <= 3; state++) {
                        dp[last][len][bal][state] +=
                            dp[last - 1][len][bal][state];
                        dp[last][len][bal][state] %= MOD;
                    }
                    if (s[last] == '(') {
                        dp[last][len + 1][bal + 1][0] +=
                            dp[last - 1][len][bal][0];
                        dp[last][len + 1][bal + 1][0] %= MOD;
                        dp[last][len + 1][bal + 1][3] +=
                            dp[last - 1][len][bal][3] +
                            dp[last - 1][len][bal][2];
                        dp[last][len + 1][bal + 1][3] %= MOD;
                        dp[last][len + 1][bal + 1][2] +=
                            dp[last - 1][len][bal][1];
                        dp[last][len + 1][bal + 1][2] %= MOD;
                    } else {
                        if (bal == 0)
                            continue;
                        dp[last][len + 1][bal - 1][1] +=
                            dp[last - 1][len][bal][0];
                        for (int state = 1; state <= 3; state++) {
                            dp[last][len + 1][bal - 1][state] +=
                                dp[last - 1][len][bal][state];
                            dp[last][len + 1][bal - 1][state] %= MOD;
                        }
                    }
                }
            }
        }

        ll ans = 0LL;
        for (ll len = 3; len <= n; len++) {

            ans += dp[n - 1][len][0][3] * (len - 2);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
