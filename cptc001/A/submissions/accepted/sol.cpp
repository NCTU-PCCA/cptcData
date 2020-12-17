#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;

int main() {
    int m, n, q;
    cin >> m >> n >> q;

    LL tmp;
    for (int i = 0; i < m * n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    
    LL h;
    while (q--) {
        cin >> h;
        cout << (int)(upper_bound(v.begin(), v.end(), h) - v.begin()) << '\n';
    }
    
}
