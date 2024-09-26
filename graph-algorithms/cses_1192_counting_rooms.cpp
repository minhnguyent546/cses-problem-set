/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 19:35:31
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
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int rooms = 0;
    vector<vector<bool>> visited(n, vector<bool>(m));
    int dr[] = {-1, 0, 0, 1};
    int dc[] = {0, -1, 1, 0};
    auto dfs = [&](auto &&self, int r, int c) -> void {
        visited[r][c] = true;
        for (int t = 0; t < 4; ++t) {
            int nr = r + dr[t];
            int nc = c + dc[t];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == '.' && !visited[nr][nc]) {
                self(self, nr, nc);
            }
        }
    };
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '.' && !visited[r][c]) {
                ++rooms;
                dfs(dfs, r, c);
            }
        }
    }
    cout << rooms << '\n';
    
    return 0;
}
