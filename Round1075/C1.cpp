#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << n << " ";
            for (int i = 2; i < n; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << "1\n";
        } else {
            cout << n - 1 << " ";
            for (int i = 2; i < n - 1; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << n << " 1\n";
        }
    }
    return 0;
}
