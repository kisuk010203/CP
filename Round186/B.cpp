#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    int small_choc[21];
    int big_choc[21];
    small_choc[1] = 0;
    big_choc[1] = 1;
    for (int i = 2; i <= 20; i++) {
        int first_choc = 0;
        int second_choc = 0;
        for (int j = 0; j < i; j+=2) {
            first_choc += (1 << j);
        }
        for (int j = 1; j < i; j+=2) {
            second_choc += (1 << j);
        }
        small_choc[i] = min(first_choc, second_choc);
        big_choc[i] = max(first_choc, second_choc);
    }
    while (T--) {
        // TODO
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int i = 1; i <= 20; i++) {
            if (small_choc[i] <= a && big_choc[i] <= b) {
                ans = i;
            } else break;
        }
        cout << ans << "\n";
    }
    return 0;
}
