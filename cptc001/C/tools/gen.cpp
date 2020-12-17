#include <bits/stdc++.h>
using namespace std;

int randint(int l, int r) {
    return rand() % (r - l) + l;
}

int _cnt[3] = {1, 3, 5};



int main() {
    srand(time(NULL) + clock());
    int T = 2;
    cout << T << '\n';
    while (T--) {
        int n = 25;
        cout << n << '\n';

        vector<pair<int, int>> v;

        int tmpi, tmpj;
        do {
            tmpi = randint(0, n), tmpj = randint(0, n);
        } while (tmpi == n - 1 && tmpj == n - 1);
        v.push_back({tmpi, tmpj});

        if (tmpi < n - 1 && tmpj > 0) {
            for (int i = 0; i < 2; i++) {
                do {
                    tmpi = randint(tmpi + 1, n);
                    tmpj = randint(0, tmpj);
                } while (tmpi == 4 && tmpj == 4);
                v.push_back({tmpi, tmpj});
                if (tmpi == n - 1 || tmpj == 0)
                    break;
            }
        }

        int cnt = _cnt[v.size()];

        if (v[0].second == n - 1) cnt--;
        if (v[v.size() - 1].first == n - 1) cnt--;

        for (int i = 0; i < v.size(); i++) {
            cout << '(' << v[i].first << ',' << v[i].second << ')';
        }
        cout << '\n';

        int total = 0;
        for (int i = 0; i < v.size(); i++) {
            total += (v[i].first + 1) * (v[i].second + 1);
            if (i > 0)
                total -= (v[i - 1].first + 1) * (v[i].second + 1);
        }

        // cout << total << '\n';

        vector<pair<int, int>> L, R;
        int cur = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = cur; j <= v[i].first; j++) {
                for (int k = 0; k < n; k++) {
                    if (k <= v[i].second) L.push_back({j, k});
                    else R.push_back({j, k});
                }
            }
            cur = v[i].first + 1;
        }
        for (int i = cur; i < n; i++)
            for (int j = 0; j < n; j++)
                R.push_back({i, j});

        // for (int i = 0; i < L.size(); i++)
        //     cout << '(' << L[i].first << ',' << L[i].second << ')';
        // cout << endl;

        int total2 = n * n - total;
        int toss = 800 * min(total, total2);

        int G[n][n] = {};

        for (int i = 0; i < toss; i++) {
            int _l = randint(0, L.size());
            int _r = randint(0, R.size());
            G[L[_l].first][L[_l].second]++;
            G[R[_r].first][R[_r].second]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << G[i][j] << ' ';
            cout << '\n';
        }
    }
}
