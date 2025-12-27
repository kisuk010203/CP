#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int cnt[26] = {0};
        int tcnt[26] = {0};
        string target;
        cin >> target;
        string s;
        cin >> s;
        for (char c : s)
            cnt[c - 'a']++;
        for (char c : target)
            tcnt[c - 'a']++;
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (tcnt[i] > cnt[i]) {
                possible = false;
                break;
            } else {
                cnt[i] -= tcnt[i];
            }
        }
        if (!possible) {
            cout << "Impossible\n";
            continue;
        }
        int cur_cnt = 0;
        int cur_tar = 0;
        string ans = "";
        while (ans.size() < s.size()) {
            // cout << "ans so far: " << ans << "! cur_cnt: " << cur_cnt << " cur_tar: " << cur_tar << "\n";
            if (cur_tar == target.size()) {
                for (int i = 0; i < 26; i++) {
                    while (cnt[i] > 0) {
                        // cout << "cnt[" << (char)('a' + i) << "] = " << cnt[i] << "\n";
                        ans += (char)('a' + i);
                        cnt[i]--;
                    }
                }
                break;
            }
            if (cur_cnt + 'a' < target[cur_tar]) {
                while (cnt[cur_cnt]--) {
                    ans += (char)(cur_cnt + 'a');
                }
                cur_cnt++;
            } else {
                ans += target[cur_tar];
                cur_tar++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
