#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {cin >> a[i].first; a[i].second = i;};
        sort(a.begin(), a.end());
        
        bool possible = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].second % 2 == a[i + 1].second % 2) {
                possible = false;
                break;
            }
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
