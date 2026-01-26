#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
        int n, h, l; cin >> n >> h >> l;
        int smaller_than_min = 0;
        int min_and_max = 0;
        if (h < l) swap(h, l); // l <= h
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x <= l) smaller_than_min++;
            else if (x <= h) min_and_max++;
        }
        int res = 0;
        if (smaller_than_min >= min_and_max) {
            res = min_and_max + (smaller_than_min - min_and_max) / 2;
        } else {
            res = smaller_than_min;
        }
        cout << min(res, n / 2) << "\n";
    }
    return 0;
}
