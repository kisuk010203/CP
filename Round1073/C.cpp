#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        if (s == t) {
            cout << "Bob\n";
            continue;
        }
        vector<int> diff;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) diff.push_back(i);
        }
        cout << "Alice\n";
        cout << diff.size() << "\n";
        for (int i = 0; i < diff.size(); i++) {
            cout << diff[i] + 1 << " ";
        } cout << "\n";
    }
    return 0;
}
