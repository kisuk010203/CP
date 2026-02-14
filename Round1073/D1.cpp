#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int open_pos = -1;
        int open_behind = 0;
        int ans = -1;
        for (int i = n - 2; i >= 0; i--) {
            open_behind += (s[i + 1] == '(' ? 1 : 0);
            if (s[i] == '(') {
                open_pos = i;
            } else if (open_pos != -1 && open_behind > open_pos - i) {
                ans = max(ans, n - 2 * (open_pos - i));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
