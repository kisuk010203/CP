#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        // TODO
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> counter(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            counter[a[i]]++;
        }
        vector<int> missing_numbers;
        for (int i = 1; i <= n; i++) {
            if (counter[i] == 0)
                missing_numbers.push_back(i);
        }
        int zero_count = missing_numbers.size();

        if (zero_count == 0) {
            for (int i = 0; i < k; i++)
                cout << a[i] << " ";
            cout << "\n";
        } else if (zero_count == 1) {
            cout << missing_numbers[0] << " ";
            vector<int> unused;
            for (int i = 1; i <= n; i++) if (i != missing_numbers[0]) unused.push_back(i);
            if (unused[0] == a[n - 1]) swap(unused[0], unused[1]);
            for (int i = 0; i < k - 1; i++)
                cout << unused[i] << " ";
            cout << "\n";
        } else { // zero_count >= 2
            if (k == 1) {
                cout << missing_numbers[0] << "\n";
                continue;
            }
            cout << missing_numbers[0] << " " << missing_numbers[1] << " ";
            vector<int> unused;
            for (int i = 1; i <= n; i++) {
                if (i != missing_numbers[0] && i != missing_numbers[1]) {
                    unused.push_back(i);
                }
            }
            for (int i = 0; i < k - 2; i++) {
                cout << unused[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
