#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int cnt = 0;
        int max_before = v[0];
        for (int i = 1; i < n; i++) {
            if (v[i] < max_before) cnt++;
            else max_before = v[i];
        }
        cout << cnt << "\n";
    }
    return 0;
}
