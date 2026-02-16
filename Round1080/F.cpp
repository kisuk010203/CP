#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Quad{
    ll a, b, c;
    bool greater_than(const Quad& other) const noexcept {
        if (a == other.a) {
            return b == other.b && c > other.c;
        }
        if (a < other.a) return false;
        ll disc = (b - other.b) * (b - other.b) - 4 * (a - other.a) * (c - other.c);
        return disc < 0;
    }
    bool operator<(const Quad& other) const noexcept {
        if (a == other.a) {
            return b == other.b ? c < other.c : b < other.b;
        }
        return a < other.a;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<Quad> quads(n);
        for (int i = 0; i < n; i++) {
            cin >> quads[i].a >> quads[i].b >> quads[i].c;
        }
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return quads[x] < quads[y];
        });
        vector<int> start_dp(n, 1);
        vector<int> end_dp(n, 1);
        for (int i = 0; i < n; i++) {
            int ri = idx[i];
            for (int j = 0; j < i; j++) {
                int rj = idx[j];
                if (quads[ri].greater_than(quads[rj])) {
                    end_dp[ri] = max(end_dp[ri], end_dp[rj] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int ri = idx[i];
            for (int j = i + 1; j < n; j++) {
                int rj = idx[j];
                if (quads[rj].greater_than(quads[ri])) {
                    start_dp[ri] = max(start_dp[ri], start_dp[rj] + 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << start_dp[i] + end_dp[i] - 1 << " ";
        }
        cout << "\n";


    }
    return 0;
}
