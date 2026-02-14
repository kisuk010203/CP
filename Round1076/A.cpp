#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n, s, x; cin >> n >> s >> x;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int y; cin >> y;
            tot += y;
        }
        s -= tot;
        if (s < 0) cout << "NO\n";
        else if (s % x == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
