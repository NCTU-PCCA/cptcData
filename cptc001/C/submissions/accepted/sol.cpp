#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL G[50][50];
LL GT[50][50];

int main() {
    int T; cin >> T; while(T--) {
        int n; cin >> n;
        LL total = 0;

        // prefix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> G[i][j];
                GT[n - i - 1][n - j - 1] = G[i][j];
                total += G[i][j];
                if (i > 0)
                    G[i][j] += G[i - 1][j];
                if (j > 0)
                    G[i][j] += G[i][j - 1];
                if (i > 0 && j > 0)
                    G[i][j] -= G[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    GT[i][j] += GT[i - 1][j];
                if (j > 0)
                    GT[i][j] += GT[i][j - 1];
                if (i > 0 && j > 0)
                    GT[i][j] -= GT[i - 1][j - 1];
            }
        }

        if (total % 2) {
            cout << "NO\n";
            continue;
        }

        total /= 2;

        int ans = 10;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (G[i][j] == total) {
                    int tmp_ans = 1;
                    if (j == n - 1) tmp_ans--;
                    if (i == n - 1) tmp_ans--;
                    ans = min(ans, tmp_ans);
                }

                for (int k = i + 1; k < n; k++) {
                    for (int l = 0; l < j; l++) {

                        if (G[i][j] + G[k][l] - G[i][l] == total) {
                            int tmp_ans = 3;
                            if (j == n - 1) tmp_ans--;
                            if (k == n - 1) tmp_ans--;
                            ans = min(ans, tmp_ans);
                        }


                        for (int s = k + 1; s < n; s++) {
                            for (int t = 0; t < l; t++) {
                                
                                if (G[i][j] + G[k][l] + G[s][t] - G[i][l] - G[k][t] == total ||
                                    GT[i][j] + GT[k][l] + GT[s][t] - GT[i][l] - GT[k][t] == total) {
                                    int tmp_ans = 5;
                                    if (j == n - 1) tmp_ans--;
                                    if (s == n - 1) tmp_ans--;
                                    ans = min(ans, tmp_ans);
                                }

                            }
                        }
                    }
                }
            }
        }

        if (ans == 10) cout << "NO\n";
        else cout << "YES " << ans << '\n';
    }
}
