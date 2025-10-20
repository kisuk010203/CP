#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        unsigned int a, b; cin >>a >> b;
        int lead_zeros_a = __builtin_clz(a);
        int lead_zeros_b = __builtin_clz(b);
        if (lead_zeros_a > lead_zeros_b) {
            cout << "-1\n";
            continue;
        }
        vector<int> diff_bits;
        for (int i = 0; i < 32; i++) {
            unsigned int mask = 1u << i;
            if ((a & mask) != (b & mask)) {
                diff_bits.push_back(mask);
            }
        }
        cout << diff_bits.size() << "\n";
        for (auto x : diff_bits) cout << x << " ";
        if (!diff_bits.empty()) cout << "\n";
    }
    return 0;
}
