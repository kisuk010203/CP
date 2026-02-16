#include <bits/stdc++.h>
using namespace std;
void print_point(int x, int y, bool newline = false) {
    cout << x << " " << y << (newline ? "\n" : " ");
}
void draw32(int x1, int y1, int x2, int y2) {
    print_point(x1, y1);
    print_point(x1, y1 + 1);
    print_point(x1 + 1, y1, true);
    print_point(x2, y2);
    print_point(x2, y2 - 1);
    print_point(x2 - 1, y2, true);
}
void draw95() {
    cout << "1 1 2 1 1 2\n";
    cout << "1 3 2 3 2 4\n";
    cout << "1 4 1 5 2 5\n";
    cout << "1 6 2 6 3 5\n";
    cout << "1 7 2 7 3 6\n";
    cout << "1 8 1 9 2 9\n";
    cout << "2 2 3 3 4 3\n";
    cout << "3 1 3 2 4 2\n";
    cout << "4 1 5 1 5 2\n";
    cout << "5 3 3 4 4 4\n";
    cout << "5 4 4 5 5 5\n";
    cout << "4 6 5 6 3 7\n";
    cout << "4 7 5 7 4 8\n";
    cout << "4 9 5 9 5 8\n";
    cout << "2 8 3 8 3 9\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << 3 * n * n << "\n";
            for (int i = 1; i < 3 * n; i+=3) {
                for (int j = 1; j < 3 * n; j+=2) {
                    draw32(i, j, i + 2, j + 1);
                }
            }
        } else if (n == 1) {
            cout << "2\n1 1 1 2 2 1\n2 3 3 2 3 3\n";
        } else {
            cout << 3 * n * n << "\n";
            for (int i = 1; i < 3 * n; i+=3) {
                for (int j = 10; j < 3 * n; j+=2) {
                    draw32(i, j, i + 2, j + 1);
                }
            }
            for (int i = 6; i < 3 * n; i += 2) {
                for (int j = 1; j < 9; j += 3) {
                    draw32(i, j, i + 1, j + 2);
                }
            }
            draw95();
            
        }
    }
    return 0;
}
