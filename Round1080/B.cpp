#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool ans = true;
        for (int st = 1; st <= n; st += 2) {
            set<int> s1;
            set<int> s2;
            for (int i = st; i <= n; i *= 2) {
                s1.insert(a[i]);
                s2.insert(i);
            }
            bool flag = true;
            for (int i : s1) {
                if (s2.count(i) == 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
