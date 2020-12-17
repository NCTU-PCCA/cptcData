#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL) + clock());
    int T = 5;
    cout << T << '\n';
    while (T--) {
        int n = 10;
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << rand() % 1000 + 1 << ' ';
            }
            cout << '\n';
        }
    }
}
