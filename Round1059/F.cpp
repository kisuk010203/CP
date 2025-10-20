#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    end:
    while (T--) {
        int n, m; cin >> n >> m;
        bitset<3000> bs[n];
        bitset<3000> full;
        for (int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            l--, r--;
            for (int j = l; j <= r; j++) {
                bs[j][i] = 1;
            }
            full[i] = 1;
        }
        // Check if zero is possible
        for (int i = 0; i < n; i++) {
            if (bs[i] == full) {
                int cur = 1;
                for (int j = 0; j < n; j++) {
                    if (j == i) cout << "0 ";
                    else cout << cur++ << " ";
                } cout << "\n";
                goto end;
            }
        }

        // Check if one is possible
        for (int i = 0; i < n - 1; i++) {
            if ((bs[i] & ~bs[i + 1]).none()) {
                // set i as 0, i + 1 as 1
                int cur = 2;
                for (int j = 0; j < n; j++) {
                    if (j == i) cout << "0 ";
                    else if (j == i + 1) cout << "1 ";
                    else cout << cur++ << " ";
                }
                cout << "\n";
                goto end;
            }
            if ((bs[i + 1] & ~bs[i]).none()) {
                // set i + 1 as 0, i as 1
                int cur = 2;
                for (int j = 0; j < n; j++) {
                    if (j == i + 1) cout << "0 ";
                    else if (j == i) cout << "1 ";
                    else cout << cur++ << " ";
                }
                cout << "\n";
                goto end;
            }
        }

        // Otherwise, two is possible
        cout << "0 2 1 ";
        for (int i = 3; i < n; i++) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
