#include <bits/stdc++.h>
using namespace std;
int n;
int query(int x, int l, int r) {
    cout << x << " " << l << " " << r << endl;
    int resp; cin >> resp;
    return resp;
}
void answer(int l, int r) {
    cout << "! " << l << " " << r << endl;
}
int diff_query(int l, int r) {
    if (l <= 0 || r <= 0 || l > r || r > n) return -1;
    return query(2, l, r) - query(1, l, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        cin >> n;
        int total = diff_query(1, n);
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            int left_diff = diff_query(left, mid);
            // cout << "DEBUG: " << left << " " << mid << " " << right << " " << left_diff << "\n";
            if (left_diff == 0) {
                left = mid + 1;
            } else if (left_diff == total) {
                right = mid;
                if (right - left + 1 == total) {
                    answer(left, right);
                    break;
                }
            } else {
                // 0 < left_diff < total
                int first_answer = diff_query(left + left_diff - total, left + left_diff - 1);
                if (first_answer == total) {
                    answer(left + left_diff - total, left + left_diff - 1);
                    break;
                } 
                int second_answer = diff_query(mid - left_diff + 1, mid - left_diff + total);
                if (second_answer == total) {
                    answer(mid - left_diff + 1, mid - left_diff + total);
                    break;
                }
            }
        }
    }
    return 0;
}
