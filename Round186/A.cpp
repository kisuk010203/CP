#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
        int n; cin >> n;
        string s; cin >> s;
        bool has_2025 = false;
        bool has_2026 = false;
        int state = 0;
        for (int i = 0; i < n; i++) {
            if (state == 0 && s[i] == '2') {
                state = 1;
            } else if (state == 1 && s[i] == '0') {
                state = 2;
            } else if (state == 2 && s[i] == '2') {
                state = 3;
            } else if (state == 3 && s[i] == '5') {
                has_2025 = true;
                state = 0;
            } else if (state == 3 && s[i] == '6') {
                has_2026 = true;
                state = 0;
            } else {
                state = 0;
            }
        }

    }
    return 0;
}
