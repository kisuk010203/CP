#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> perm(n, 0);
        for (int i = 0; i < n; i++) cin >> perm[i];
        int l = 0;
        while (l < n && perm[l] == n - l) l++;
        if (l == n) {
            for (int i : perm) cout << i << " ";
            cout << "\n";
            continue;
        }
        int r = l + 1;
        while (r < n && perm[r] != n - l) r++;
        reverse(perm.begin() + l, perm.begin() + r + 1);
        for (int i : perm) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
