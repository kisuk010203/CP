#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> v(n + 1);
        v[0] = 0;
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            if (i == r) {
                v[i] = v[l - 1];
            } else {
                v[i] = cur++;
            }
        }
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = v[i] ^ v[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
