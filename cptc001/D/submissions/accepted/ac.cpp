#include <bits/stdc++.h>
using namespace std;
string query(int x) {
    cout << "? " << x << endl;
    string ret; cin >> ret;
    return ret;
}
int main() {
    int l = 0, r = 1000;
    for (auto &step : {100, 10, 1}) {
        for (int i = l ; i < r ; i += step) {
            if (query(i + step)[0] == 'S') {
                l = i + step;
            } else {
                r = i + step;
                break;
            }
        }
    }
    cout << "! " << l << endl;
}
