#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
struct Edge {
    int st, en;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ll> v(n);
        set<ll> s;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            s.insert(v[i]);
        }
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].st >> edges[i].en;
            edges[i].st--;
            edges[i].en--;
        }
        sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b) {
            ll a_sum = v[a.st] + v[a.en];
            ll b_sum = v[b.st] + v[b.en];
            if (a_sum == b_sum)
                return a.st < b.st;
            return a_sum < b_sum;
        });
        vector<ll> dp(m, 0);
        vector<ll> suf(m + 1, 0); // suf[i] = sum(dp[i:])
        dp[m - 1] = 1;
        suf[m - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            // cout << "Processing edge " << i << " (" << edges[i].st << ", " << edges[i].en << ")\n";
            ll nxt = v[edges[i].st] + v[edges[i].en];
            if (s.find(nxt) == s.end()) {
                dp[i] = 1;
            } else {
                // cout << "Looking for edges with sum " << nxt << "\n";
                // binary search for edges with st == edges[i].en and sum == nxt
                auto cmp_lb = [&](const Edge &e, int val) {
                    ll sum = v[e.st] + v[e.en];
                    ll nxt_sum = nxt + v[val];
                    if (sum != nxt_sum)
                        return sum < nxt_sum;
                    
                    return e.st < val;
                };
                auto cmp_ub = [&](int val, const Edge &e) {
                    ll sum = v[e.st] + v[e.en];
                    ll nxt_sum = nxt + v[val];
                    if (sum != nxt_sum)
                        return sum > nxt_sum;
                    return e.st > val;
                };
                auto lb = lower_bound(edges.begin() + i + 1, edges.end(),
                                      edges[i].en, cmp_lb);
                auto ub = upper_bound(edges.begin() + i + 1, edges.end(),
                                      edges[i].en, cmp_ub);
                // for (auto e : edges) {
                //     cout << cmp_ub(edges[i].en, e) << " ";
                // }
                // cout << "is the result for " << edges[i].en << "\n";
                if (lb == ub) {
                    dp[i] = 1;
                    // cout << "lidx == " << lb - edges.begin() << ", uidx == " << ub - edges.begin() << "\n"; 
                } else {
                    int lidx = lb - edges.begin();
                    int uidx = ub - edges.begin();
                    dp[i] = suf[lidx] - suf[uidx] + 1 + MOD;
                    dp[i] %= MOD;
                    // cout << "dp[" << i << "] = suf[" << lidx << "] - suf[" << uidx << "] = " << dp[i] << "\n";
                }
            }
            suf[i] = suf[i + 1] + dp[i];
            suf[i] %= MOD;
        }
        // for (int i = 0; i < m; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";
        cout << suf[0] << "\n";
    }
    return 0;
}