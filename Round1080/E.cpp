#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
void dfs(int u, vector<ll>& parent, vector<ll>& left, vector<ll>& right, vector<ll>& up_time) {
    if (left[u] == 0 && right[u] == 0) {
        up_time[u] = 1;
        return;
    }
    dfs(left[u], parent, left, right, up_time);
    dfs(right[u], parent, left, right, up_time);
    up_time[u] = (up_time[left[u]] + up_time[right[u]] + 3) % MOD;
}
void dfs2(int u, vector<ll>& parent, vector<ll>& left, vector<ll>& right, vector<ll>& up_time, vector<ll>& ans) {
    ans[u] = (ans[parent[u]] + up_time[u]) % MOD;
    if (left[u] == 0 && right[u] == 0) {
        return;
    }
    dfs2(left[u], parent, left, right, up_time, ans);
    dfs2(right[u], parent, left, right, up_time, ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> parent(n + 1, 0), left(n + 1, 0), right(n + 1, 0), up_time(n + 1, 0L);
        for (int i = 1; i <= n; i++) {
            cin >> left[i] >> right[i];
            if (left[i] != 0) {
                parent[left[i]] = i;
            }
            if (right[i] != 0) {
                parent[right[i]] = i;
            }
        }
        int root = 0;
        dfs(1, parent, left, right, up_time);
        vector<ll> ans(n + 1, 0L);
        dfs2(1, parent, left, right, up_time, ans);
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
