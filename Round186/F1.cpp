#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
ll comb[1001][1001];
void build_comb() {
    for (ll n = 0; n <= 1000; n++) comb[n][0] = 1;
    for (ll n = 1; n <= 1000; n++) {
        for (ll r = 1; r <= n; r++) {
            comb[n][r] = comb[n - 1][r - 1] + comb[n - 1][r];
            comb[n][r] %= MOD;
        }
    }
}
ll dp(vector<ll>& cnt, vector<ll>& remain, int idx, ll target) {
    if (idx < 0) {
        return target == 0 ? 1 : 0;
    }
    if (cnt[idx] == 0) {
        return dp(cnt, remain, idx - 1, target);
    }
    if (target <= (1L << idx)) {
        return ((1L << remain[idx]) % MOD + dp(cnt, remain, idx - 1, target)) % MOD;
    }
    if (target >= (1L << (idx + 1)) || remain[idx] == 0) {
        return 0;
    }
    cout << "At idx " << idx << " with target " << target << "\n";
    ll res = 0;
    for (ll take = 1; take <= cnt[idx]; take++) {
        ll new_target = (target - (1L << idx)) << 1;
        ll add = dp(cnt, remain, idx - 1, new_target);
        add *= comb[cnt[idx]][take];
        add %= MOD;
        res += add;
        res %= MOD;
    }
    return res;
}
ll solve(vector<ll>& cnt, ll target) {
    cout << "Solving for target " << target << "\n";
    vector<ll> remain(61, 0);
    for (int i = 59; i >= 0; i--) {
        remain[i] = remain[i + 1] + cnt[i + 1];
    }
    return dp(cnt, remain, 60, target);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<ll> cnt(61, 0);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        cnt[x]++;
    }
    build_comb();
    while(m--) {
        ll type, target;
        cin >> type >> target;
        if (type == 1) cnt[target]++;
        else if(type == 2) cnt[target]--;
        else {
            ll res = solve(cnt, target);
            cout << res << "\n";
        }
    }
    
    return 0;
}
