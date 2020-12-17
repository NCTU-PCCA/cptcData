#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e5;
const int mod = 1e9 + 7;
int a[105];
ll dp[105][2][11];
ll dfs(int now, int lim ,int last) {
    if (now == -1) {
        return 1;
    }
    if (~dp[now][lim][last]) {
        return dp[now][lim][last];
    }
    int ub = lim ? a[now] : 9;
    ll ans = 0;
    for (int i = 0 ; i <= ub ; i++) {
        if (i == last)continue;
        if (last == 10 && !i)
            ans += dfs(now - 1, lim && i == ub, 10);
        else
            ans += dfs(now - 1, lim && i == ub, i);
        ans %= mod;
    }
    return dp[now][lim][last] = ans;
}
ll solve(string s) {
    memset(dp, -1, sizeof(dp));
    int ptr = 0;
    while (s.size()) {
        a[ptr] = s.back() - '0';
        s.pop_back();
        ptr++;
    }
    return dfs(ptr - 1, 1, 10);
}
bool check(string s) {
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (s[i] == s[i - 1]) return 0;
    }
    return 1;
}
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1 >> s2;
        cout << (solve(s2) - solve(s1) + check(s1) + mod) % mod << '\n';
    }
}