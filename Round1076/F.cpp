#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Vert {
    ll x;
    vector<ll> ys;
    ll size() {
        return ys.size();
    }
    ll min() {
        return ys[0];
    }
    ll max() {
        return ys.back();
    }
};
ll get_cost(ll m, ll M, ll s, bool end_max) {
    if (end_max) {
        if (s <= m) return M - s;
        else return (s - m) + (M - m);
    } else {
        if (s >= M) return s - m;
        else return (M - s) + (M - m);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
        vector<Vert> verts;
        verts.push_back({ax, {ay}});
        vector<pair<ll, ll>> polls(n);
        for (ll i = 0; i < n; i++) {
            cin >> polls[i].first;
        }
        for (ll i = 0; i < n; i++) {
            cin >> polls[i].second;
        }
        sort(polls.begin(), polls.end());
        for (auto [x, y] : polls) {
            if (verts.back().x == x) {
                verts.back().ys.push_back(y);
            } else {
                verts.push_back({x, {y}});
            }
        }

        vector<vector<ll>> costs(verts.size(), vector<ll>(2, 0));
        assert(verts[0].x == ax);

        for (auto &vert : verts) {
            sort(vert.ys.begin(), vert.ys.end());
            // cout << vert.x << ": ";
            // for (auto y : vert.ys) cout << y << " ";
            // cout << "\n";
        }
        if (verts[0].size() > 1) {
            costs[0][0] = get_cost(verts[0].min(), verts[0].max(), ay, false);
            costs[0][1] = get_cost(verts[0].min(), verts[0].max(), ay, true);
        }
        for (ll i = 1; i < verts.size(); i++) {
            ll m = verts[i].min(), M = verts[i].max();
            ll xdiff = verts[i].x - verts[i - 1].x;
            costs[i][0] = min(
                costs[i - 1][0] + get_cost(m, M, verts[i - 1].min(), false) + xdiff,
                costs[i - 1][1] + get_cost(m, M, verts[i - 1].max(), false) + xdiff
            );
            costs[i][1] = min(
                costs[i - 1][0] + get_cost(m, M, verts[i - 1].min(), true) + xdiff,
                costs[i - 1][1] + get_cost(m, M, verts[i - 1].max(), true) + xdiff
            );
        }
        ll xdiff = bx - verts.back().x;
        ll ans_min = costs.back()[0] + xdiff + abs(verts.back().min() - by);
        ll ans_max = costs.back()[1] + xdiff + abs(verts.back().max() - by);
        cout << min(ans_min, ans_max) << "\n";

    }
    return 0;
}
