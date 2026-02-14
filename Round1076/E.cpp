#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    constexpr int MAXN = 3e5 + 1;
    vector<vector<int>> divisors(MAXN, vector<int>()); // small divisors of i
    for (int i = 4; i < MAXN; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                divisors[i].push_back(j);
            }
        }
    }
    while (T--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        constexpr int INF = 1e9;
        vector<int> ans(n + 1, INF);
        for (int i = 1; i <= n; i++) {
            if (s.count(i)) {
                ans[i] = 1;
            } else {
                for (int d : divisors[i]) {
                    // cout << "Trying " << i << " = " << d << " * " << i / d << "\n";
                    if (ans[d] != INF && ans[i / d] != INF) {
                        ans[i] = min(ans[i], ans[d] + ans[i / d]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] == INF) cout << -1 << " ";
            else cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
