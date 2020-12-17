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
string gen() {
    int len = rand() % 99 + 1;
    string ret;
    ret += (rand() % 9) + '1';
    f(len - 1) {
        ret += (rand() % 10) + '0';
    }
    return ret;
}
bool ok(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return 0;
    }
    if (s1.size() < s2.size()) {
        return 1;
    }
    f(s1.size()) {
        if (s1[i] > s2[i]) {
            return 0;
        }
        else if (s1[i] < s2[i]) {
            return 1;
        }
    }
    return 1;
}
int main() {
    srand(time(NULL));
    int t = 20;
    cout << t << '\n';
    while (t--) {
        while(1) { 
            string s1 = gen();
            string s2 = gen();
            if (ok (s1, s2)) {
                cout << s1 <<' '<<s2 <<'\n';
                break;
            }
        }
    }
}