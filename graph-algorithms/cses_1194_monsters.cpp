/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-09-25 10:27:39
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> que;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                que.emplace_back(i, j);
                dist[i][j] = 0;
            }
        }
    }

    const int dirs = 4;
    const int dr[] = {-1, 0, 0, 1};
    const int dc[] = {0, -1, 1, 0};
    const string str_dirs = "ULRD";
    for (int k = 0; k < (int) que.size(); ++k) {
        auto [r, c] = que[k];
        for (int t = 0; t < dirs; ++t) {
            int nr = r + dr[t];
            int nc = c + dc[t];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && (grid[nr][nc] == '.' || grid[nr][nc] == 'M')) {
                if (dist[nr][nc] > dist[r][c] + 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    que.emplace_back(nr, nc);
                }
            }
        }
    }

    que.clear();
    vector<vector<int>> dist2(n, vector<int>(m, INF));
    vector<vector<int>> trace(n, vector<int>(m, -1));

    for (int i = 0; i < n && que.empty(); ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                que.emplace_back(i, j);
                dist2[i][j] = 0;
                break;
            }
        }
    }
    for (int k = 0; k < (int) que.size(); ++k) {
        auto [r, c] = que[k];

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            if (dist2[r][c] < dist[r][c] && grid[r][c] != 'M') {
                cout << "YES" << '\n';
                string path = "";
                int cur_r = r;
                int cur_c = c;
                while (cur_r != que[0].first || cur_c != que[0].second) {
                    int z = trace[cur_r][cur_c];
                    assert(z != -1);
                    path += str_dirs[z];
                    cur_r -= dr[z];
                    cur_c -= dc[z];
                }
                reverse(path.begin(), path.end());
                cout << path.size() << '\n';
                cout << path << '\n';
                return 0;
            }
        }

        for (int t = 0; t < dirs; ++t) {
            int nr = r + dr[t];
            int nc = c + dc[t];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] != '#') {
                if (dist2[nr][nc] > dist2[r][c] + 1) {
                    dist2[nr][nc] = dist2[r][c] + 1;
                    trace[nr][nc] = t;
                    que.emplace_back(nr, nc);
                }
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}
