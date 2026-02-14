#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
vector<int> children[MAXN];
int subtree_size[MAXN];
int n;
bool found;

void dfs_size(int u, int p) {
    subtree_size[u] = 1;
    children[u].clear();
    for (int v : adj[u]) {
        if (v != p) {
            children[u].push_back(v);
            dfs_size(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

int find_centroid(int u, int p) {
    for (int v : adj[u]) {
        if (v != p && subtree_size[v] > n / 2) {
            return find_centroid(v, u);
        }
    }
    return u;
}

int query(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int res;
    cin >> res;
    return res;
}

void guess(int u) {
    cout << "! " << u << endl;
    found = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs_size(1, -1);
        int centroid = find_centroid(1, -1);
        dfs_size(centroid, -1);

        auto cmp = [](int a, int b) {
            return subtree_size[a] < subtree_size[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        set<int> visited;

        pq.push(centroid);
        visited.insert(centroid);
        for (int child : children[centroid]) {
            pq.push(child);
            visited.insert(child);
        }

        found = false;
        while (!found && pq.size() >= 2) {
            int u = pq.top(); pq.pop();
            int v = pq.top(); pq.pop();

            int res = query(u, v);

            if (res == 1) {
                if (query(u, u) == 1) guess(u);
                else guess(v);
                found = true;
                continue;
            }

            for (int child : children[u]) {
                if (!visited.count(child)) {
                    pq.push(child);
                    visited.insert(child);
                }
            }
            for (int child : children[v]) {
                if (!visited.count(child)) {
                    pq.push(child);
                    visited.insert(child);
                }
            }
        }

        if (!found && pq.size() == 1) {
            guess(pq.top());
        }
    }

    return 0;
}