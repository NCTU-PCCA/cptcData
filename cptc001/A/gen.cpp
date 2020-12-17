#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(clock());
    
    int n = rand() % 1000 + 1;
    int m = 100000 / n;
    int q = rand() % 1000 + 100000 - 1000 + 1;

    cout << n << ' ' << m << ' ' << q << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << rand() % 100000000 + 1 << ' ';
        cout << '\n';
    }

    for (int i = 0; i < q; i++) {
        cout << rand() % 100000000 + 1 << '\n';
    }
}
