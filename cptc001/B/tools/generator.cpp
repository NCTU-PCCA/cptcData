#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    if (argc - 1 != 4) {
        cout << "Usage: " << argv[0] << " <n> <m> <lb> <ub>\n";
        return 1;
    }
    srand(time(NULL));
    int n  = atoi(argv[1]);
    int m  = atoi(argv[2]);
    int lb = atoi(argv[3]);
    int ub = atoi(argv[4]);

    cout << n << ' ' << m << '\n';
    set<pair<int, int>> st;
    while (m--) {
        int u = rand() % n;
        int v = rand() % n;
        if (u == v) {
            m++;
            continue;
        }
        if (u > v)
            swap(u, v);
        if (st.count({u, v})) {
            m++;
            continue;
        }
        cout << u + 1 << ' ' << v + 1 << '\n';
        st.insert({u, v});
    }
    for (int i = 0 ; i < n ; i++)
        cout << rand() % (ub - lb + 1) + lb << " \n"[i + 1 == n];
}
