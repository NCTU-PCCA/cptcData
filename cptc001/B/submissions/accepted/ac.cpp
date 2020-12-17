#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    assert(1 <= n && n <= 2e5);
    assert(0 <= m && m <= 1e6);
    vector<int> deg(n, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(u < v);
        u--, v--;
        deg[u]++; deg[v]++;
    }
    sort(deg.begin(), deg.end());
    reverse(deg.begin(), deg.end());
    vector<int> arr(n);
    for (auto &v : arr) {
        cin >> v;
        assert(1 <= v && v <= 1e6);
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int i = 0 ; i < n ; i++)
        ans += 1ll * deg[i] * arr[i];
    cout << ans << '\n';
}
