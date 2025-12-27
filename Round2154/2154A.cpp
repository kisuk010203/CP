#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                continue;
            bool canPlace = true;
            for (int j = max(0, i - k + 1); j < i; j++) {
                if (s[j] == '1')
                    canPlace = false;
            }
            if (canPlace)
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
