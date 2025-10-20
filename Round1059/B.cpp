#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> zeros;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeros.push_back(i);
            }
        }
        cout << zeros.size() << "\n";
        for (auto x : zeros) cout << x + 1 << " ";
        cout << "\n";

    }
    return 0;
}
