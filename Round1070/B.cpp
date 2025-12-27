#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        s = s + s;
        int longest_zero = 0;
        int current_zero = 0;
        for (char c : s) {
            if (c == '0')
                current_zero++;
            else {
                longest_zero = max(longest_zero, current_zero);
                current_zero = 0;
            }
        }
        longest_zero = max(longest_zero, current_zero);
        cout << longest_zero << "\n";
    }
    return 0;
}
