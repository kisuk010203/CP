#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<pair<ll, ll>> greedy_is;
        greedy_is.push_back({v[0], 0});
        for (ll i = 1; i < n; i++) {
            if (v[i] > greedy_is.back().first) {
                greedy_is.push_back({v[i], i});
            }
        }
        ll new_n = greedy_is.size();

        long long dp[k + 1][k + 1];         // index, used, current max
        long long max_dp[new_n + 1][k + 1]; // index, used
        ll ans = -1L;
        for (ll i = 0; i <= new_n; i++) {
            for (ll j = 0; j <= k; j++) {
                for (ll l = 0; l <= k; l++) {
                    dp[j][l] = -1L;
                }
                max_dp[i][j] = -1L;
            }
        }
        for (int i = 0; i < new_n; i++) {
            if (i + 1 < new_n)
                greedy_is[i].second =
                    greedy_is[i + 1].second - greedy_is[i].second;
            else
                greedy_is[i].second = n - greedy_is[i].second;
        }
        for (ll i = 0; i <= min(k, greedy_is[0].first); i++) {
            dp[i][i] = i * greedy_is[0].second;
            max_dp[0][i] = i * greedy_is[0].second;
            ans = max(ans, (long long)i * greedy_is[0].second);
        }

        for (ll i = 1; i < new_n; i++) {
            ll new_dp[k + 1][k + 1];
            for (ll used = 0; used <= k; used++) {
                for (ll cur_max = 0; cur_max <= k; cur_max++) {
                    new_dp[used][cur_max] = -1L;
                }
            }
            for (ll used = 0; used <= k; used++) {
                for (ll cur_max = 0;
                     cur_max <= min({k, greedy_is[i].first, used}); cur_max++) {
                    new_dp[used][cur_max] = dp[used][cur_max];
                    if (used >= cur_max && max_dp[i - 1][used - cur_max] != -1L)
                        new_dp[used][cur_max] = max(
                            dp[used][cur_max], max_dp[i - 1][used - cur_max]);
                    if (new_dp[used][cur_max] != -1L)
                        new_dp[used][cur_max] += cur_max * greedy_is[i].second;
                    else
                        continue;
                    ans = max(ans, new_dp[used][cur_max]);
                    max_dp[i][used] =
                        max(max_dp[i][used], new_dp[used][cur_max]);
                    // cout << "dp[" << i << "][" << used << "][" << cur_max
                    //      << "] = " << new_dp[used][cur_max] << "\n";
                }
            }
            for (ll used = 0; used <= k; used++) {
                for (ll cur_max = 0; cur_max <= k; cur_max++) {
                    dp[used][cur_max] = new_dp[used][cur_max];
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
