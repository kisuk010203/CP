#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[x]++;
        }
        bool possible = true;
        if (a[0] == 0) possible = false;
        if (a[0] >= 2) possible = (a[1] > 0);
        cout << (possible ? "YES\n" : "NO\n");

    }
    return 0;
}
