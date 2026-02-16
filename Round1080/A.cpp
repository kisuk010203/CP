#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = false;
        for (int item : a) if (item == 67) {
            cout << "YES\n";
            flag = true;
            break;
        }
        if (!flag) cout << "NO\n";
    }
    return 0;
}
