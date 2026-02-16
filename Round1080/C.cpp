#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int block = 1;
        int prev = a[0];
        for (int i = 1; i < n; i++) {
            int cur = a[i];
            if (cur == prev || cur + prev == 7) {
                block++;
            } else {
                ans += (block / 2);
                // cout << "Block: " << block << "\n";
                block = 1;
            }
            prev = cur;
        }
        ans += (block / 2);
        // cout << "Block: " << block << "\n";
        cout << ans << "\n";
    }
    return 0;
}
