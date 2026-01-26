#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Person {
    ll x;
    ll y;
    ll z;
    ll idx;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        // TODO
        ll n, m, k; cin >> n >> m >> k;
        vector<Person> friends(n);
        vector<ll> boxes(m);
        for (ll i = 0; i < m; i++) cin >> boxes[i];
        sort(boxes.begin(), boxes.end());
        for (ll i = 0; i < n; i++) {
            cin >> friends[i].x >> friends[i].y >> friends[i].z;
        }
        sort(friends.begin(), friends.end(), [](Person a, Person b) {
            return a.x < b.x;
        });
        for (ll i = 0; i < n; i++) {
            friends[i].idx = i;
        }

        ll idx = 0;
        ll happy = 0;
        vector<bool> used(n, false);
        auto cmp = [](Person a, Person b) { return a.z - a.y < b.z - b.y; };
        priority_queue<Person, vector<Person>, decltype(cmp)> pq(cmp);
        for (auto beauty : boxes) {
            while (idx < n && friends[idx].x <= beauty) {
                pq.push(friends[idx]);
                idx++;
            }
            if (!pq.empty()) {
                Person p = pq.top();
                pq.pop();
                used[p.idx] = true;
                happy++;
            }
        }

        ll total_y = 0;
        vector<Person> unused_friends;
        for (ll i = 0; i < n; i++) {
            total_y += friends[i].y;
            if (!used[i]) {
                unused_friends.push_back(friends[i]);
            }
        }
        ll remain = k - total_y;
        sort(unused_friends.begin(), unused_friends.end(), [](Person a, Person b) {
            return a.z - a.y < b.z - b.y;
        });
        for (auto f : unused_friends) {
            if (remain >= f.z - f.y) {
                remain -= (f.z - f.y);
                happy++;
            } else break;
        }
        cout << happy << "\n";

    }
    return 0;
}
