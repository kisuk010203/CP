#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]++;
        }
        sort(v.begin(), v.end());
        int cur = freq.size();
        int ans = *lower_bound(v.begin(), v.end(), cur);
        cout << ans << "\n";
    }
    return 0;
}
