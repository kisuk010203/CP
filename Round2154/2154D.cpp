#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int depth;
    bool onPath;
    const bool operator<(const Node& other) const {
        return depth > other.depth;
    }
};

bool dfs(int curr, vector<int> *adj, vector<Node> &nodes) {
    bool res = nodes[curr].onPath;
    for (auto child : adj[curr]) {
        if (nodes[child].depth == -1) {
            nodes[child].depth = nodes[curr].depth + 1;
            res |= dfs(child, adj, nodes);
        }
    }
    return nodes[curr].onPath = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> adj[n + 1]; 
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Tree has root as 0
        vector<Node> nodes(n + 1);
        for (int i = 1; i < n + 1; i++) {
            nodes[i].val = i;
            nodes[i].depth = -1;
            nodes[i].onPath = false;
        }
        nodes[1].depth = 0;
        nodes[n].onPath = true;
        dfs(1, adj, nodes);
        
        sort(nodes.begin(), nodes.end());
        int instruction_cnt = 0;
        vector<string> instruction_set;
        for (auto node : nodes) {
            if (node.val == 0) continue;
            if (node.onPath) continue;
            instruction_set.push_back("1");
            instruction_cnt++;
            if (instruction_cnt % 2 == node.depth % 2) {
                instruction_set.push_back("1");
                instruction_cnt++;
            }
            instruction_set.push_back("2 " + to_string(node.val));
        }

        instruction_set.push_back("1");
        instruction_cnt++;
        reverse(nodes.begin(), nodes.end());
        for (auto node : nodes) {
            if (node.val == 0 || !node.onPath || node.val == n) continue;
            if (instruction_cnt % 2 == node.depth % 2) {
                instruction_set.push_back("1");
                instruction_cnt++;
            }
            instruction_set.push_back("2 " + to_string(node.val));
        }

        cout << instruction_set.size() << "\n";
        for (const auto& instruction : instruction_set) {
            cout << instruction << "\n";
        }
    }
}