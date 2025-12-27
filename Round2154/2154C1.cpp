#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int MAXN = 200002;
    vector<int> spf(MAXN);
    for (int i = 1; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<bool> freq(MAXN, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool has_non_coprime = false;
        for (int i = 0; i < n; i++) {
            if (has_non_coprime)
                break;
            int x = a[i];
            while (x > 1) {
                int p = spf[x];
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
        for (int i = 0; i < n; i++) {
            if (has_non_coprime)
                break;
            int x = a[i] + 1;
            while (x > 1) {
                int p = spf[x];
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
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
    return 0;
}