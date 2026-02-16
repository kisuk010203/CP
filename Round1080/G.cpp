#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr int LOG = 20;
void dfs(int u, vector<ll> &parent, vector<ll> &left, vector<ll> &right,
         vector<ll> &up_time) {
    if (left[u] == 0 && right[u] == 0) {
        up_time[u] = 1;
        return;
    }
    dfs(left[u], parent, left, right, up_time);
    dfs(right[u], parent, left, right, up_time);
    up_time[u] = (up_time[left[u]] + up_time[right[u]] + 3) % MOD;
}
void dfs3(int u, vector<ll> &left, vector<ll> &right, vector<ll> &dfs_pos,
          vector<ll> &tour) {
    dfs_pos[u] = tour.size();
    tour.push_back(u);
    if (left[u] != 0 && right[u] != 0) {
        dfs3(left[u], left, right, dfs_pos, tour);
        tour.push_back(u);
        dfs3(right[u], left, right, dfs_pos, tour);
        tour.push_back(u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<ll> parent(n + 1, 0), left(n + 1, 0), right(n + 1, 0),
            up_time(n + 1, 0L);
        vector<ll> dfs_pos(n + 1, 0L);
        vector<ll> tour;
        tour.reserve(n << 1);
        vector<vector<ll>> sparse_parent(n + 1, vector<ll>(LOG, 0));
        vector<vector<ll>> sparse_up_time(n + 1, vector<ll>(LOG, 0));
        for (int i = 1; i <= n; i++) {
            cin >> left[i] >> right[i];
            if (left[i] != 0) {
                parent[left[i]] = i;
            }
            if (right[i] != 0) {
                parent[right[i]] = i;
            }
        }
        dfs(1, parent, left, right, up_time);
        dfs3(1, left, right, dfs_pos, tour);
        for (int i = 1; i <= n; i++) {
            sparse_parent[i][0] = parent[i];
            sparse_up_time[i][0] = up_time[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                sparse_parent[i][j] =
                    sparse_parent[sparse_parent[i][j - 1]][j - 1];
                sparse_up_time[i][j] =
                    min(MOD, sparse_up_time[i][j - 1] +
                     sparse_up_time[sparse_parent[i][j - 1]][j - 1]);
            }
        }
        while (q--) {
            ll v, k;
            cin >> v >> k;
            for (int j = LOG - 1; j >= 0; j--) {
                if (sparse_parent[v][j] != 0 && sparse_up_time[v][j] <= k) {
                    k -= sparse_up_time[v][j];
                    v = sparse_parent[v][j];
                }
            }
            cout << tour[dfs_pos[v] + k] << " ";
        }
        cout << "\n";
    }
    return 0;
}
