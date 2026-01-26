#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
        int n; cin >> n;

        if (n % 2 == 1) {
            cout << n - 1 << " ";
            for (int i = 2; i < n - 1; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << n << " 1\n";
        }
        else {
            if ((n & (n - 1)) == 0) {
                cout << "-1\n";
                continue;
            }
            int lowest_pow2 = 1;
            while (lowest_pow2 * 2 <= n) {
                lowest_pow2 *= 2;
                if (lowest_pow2 & n) break;
            }
            cout << lowest_pow2 << " ";
            for (int i = 2; i <= lowest_pow2; i++) {
                cout << (i % 2 == 0 ? i + 1 : i - 1) << " ";
            }
            cout << n << " ";
            for (int i = lowest_pow2 + 2; i < n - 1; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << "1\n";
        }
    }
    return 0;
}
