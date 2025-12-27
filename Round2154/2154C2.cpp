#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 400002
vector<ll> spf(MAXN);

void calculate_spf() {
    for (ll i = 1; i < MAXN; i++) { spf[i] = i; }
    for (ll i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    calculate_spf();

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<bool> freq(MAXN, false);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool has_non_coprime = false;

        // find if there are non-coprime elements in a
        for (ll i = 0; i < n; i++) {
            if (has_non_coprime)
                break;
            ll x = a[i];
            while (x > 1) {
                ll p = spf[x];
                if (freq[p]) {
                    has_non_coprime = true;
                    break;
                }
                freq[p] = true;
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (has_non_coprime) {
            cout << "0\n";
            continue;
        }

        // wandering with the smallest two
        int min_idx = -1, second_min_idx = -1;
        for (ll i = 0; i < n; i++) {
            if (min_idx == -1 || b[i] < b[min_idx]) {
                second_min_idx = min_idx;
                min_idx = i;
            } else if (second_min_idx == -1 || b[i] < b[second_min_idx]) {
                second_min_idx = i; 
            }
        }
        // try changing min_idx and second_min_idx
        long long res = b[min_idx] * (a[min_idx] % 2) + b[second_min_idx] * (a[second_min_idx] % 2);
        vector<ll> min_indices;
        for (ll i = 0; i < n; i++) {
            if (b[i] == b[min_idx]) {
                min_indices.push_back(i);
            }
        }
        if (min_indices.size() == 1) {
            ll cnt = 1;
            freq.assign(MAXN, false);
            for (ll i = 0; i < n; i++) {
                if (i == min_idx) continue;
                ll x = a[i];
                while (x > 1) {
                    ll p = spf[x];
                    freq[p] = true;
                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }
            while (res > b[min_idx] * cnt) {
                ll x = a[min_idx] + cnt;
                while (x > 1) {
                    ll p = spf[x];
                    if (freq[p]) {
                        has_non_coprime = true;
                        break;
                    }
                    while (x % p == 0) {
                        x /= p;
                    }
                }
                if (has_non_coprime) {
                    break;
                }
                cnt++;
            }
            if (has_non_coprime) {
                res = min(res, b[min_idx] * cnt);
            }
        }
        else { // there are two or more of the min indices
            for (auto i : min_indices) {
                if (has_non_coprime) break;
                ll x = a[i] + 1;
                while (x > 1) {
                    ll p = spf[x];
                    if (freq[p]) {
                        has_non_coprime = true;
                        break;
                    }
                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }
            if (has_non_coprime) {
                res = min(res, b[min_idx]);
            }

        }

        cout << res << "\n";
    }
    return 0;
}