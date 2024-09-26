/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 19:40:19
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    pair<int, int> start = {-1, -1}, end = {-1, -1};
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
            else if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    assert(start != make_pair(-1, -1));
    assert(end != make_pair(-1, -1));
    assert(start != end);
    vector<vector<int>> trace(n, vector<int>(m, -1));
    string dirs = "ULRD";
    int dr[] = {-1, 0, 0, 1};
    int dc[] = {0, -1, 1, 0};
    vector<pair<int, int>> que;
    que.emplace_back(start);
    trace[start.first][start.second] = INF;
    for (int i = 0; i < (int) que.size(); ++i) {
        auto [r, c] = que[i];
        for (int t = 0; t < (int) dirs.length(); ++t) {
            int nr = r + dr[t];
            int nc = c + dc[t];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] != '#' && trace[nr][nc] == -1) {
                trace[nr][nc] = t;
                que.emplace_back(nr, nc);
            }
        }
    }
    if (trace[end.first][end.second] == -1) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    string path = "";
    auto [cur_r, cur_c] = end;
    while (cur_r != start.first || cur_c != start.second) {
        int t = trace[cur_r][cur_c];
        assert(t != -1);
        path += dirs[t];
        cur_r -= dr[t];
        cur_c -= dc[t];
    }
    reverse(path.begin(), path.end());
    cout << path.length() << '\n';
    cout << path << '\n';
    return 0;
}
