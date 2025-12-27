#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> maxTill(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxTill[i] = a[i];
            if (i > 0) {
                maxTill[i] = max(maxTill[i], maxTill[i - 1]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i+=2) {
            int minLR = INT_MAX;
            if (i > 0) minLR = min(minLR, maxTill[i - 1]);
            if (i + 1 < n) minLR = min(minLR, maxTill[i + 1]);
            if (a[i] >= minLR) {
                cnt += (a[i] - minLR + 1);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}