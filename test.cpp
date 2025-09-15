#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int xs, ys; 
        cin >> xs >> ys;
        int sx, sy; 
        cin >> sx >> sy;
        int m; 
        cin >> m;

        vector<pair<int,int>> p(m + 1);
        p[0] = {sx, sy};
        for (int i = 1; i <= m; ++i) {
            int x, y; 
            cin >> x >> y;
            p[i] = {x, y};
        }

        vector<vector<int>> dist(m + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                dist[i][j] = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);

        int ALL = (m ? (1 << m) - 1 : 0);
        const int INF = 1e9;

        vector<vector<int>> dp(1 << m, vector<int>(m + 1, INF));
        dp[0][0] = 0;

        for (int mask = 0; mask <= ALL; ++mask) {
            for (int u = 0; u <= m; ++u) {
                int cur = dp[mask][u];
                if (cur == INF) continue;
                for (int v = 1; v <= m; ++v) {
                    if (((mask >> (v - 1)) & 1) == 0) {
                        int nmask = mask | (1 << (v - 1));
                        dp[nmask][v] = min(dp[nmask][v], cur + dist[u][v]);
                    }
                }
            }
        }

        int ans = INF;
        for (int u = 0; u <= m; ++u) ans = min(ans, dp[ALL][u] + dist[u][0]);
        cout << ans << '\n';
    }
    return 0;
}