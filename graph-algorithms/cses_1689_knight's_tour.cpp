/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-08-03 00:12:32
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
    int n = 8, m = 8;
    int r, c;
    cin >> c >> r;
    --r; --c;

    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));

    auto in_grid = [&](int i, int j) {
        return (0 <= i && i < n && 0 <= j && j < m);
    };
    auto print = [&]() -> void {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cerr << vis[i][j] << ' ';
            }
            cerr << '\n';
        }
    };
    auto num_moves = [&](int i, int j) {
        int cnt = 0;
        for (int di = -2; di <= 2; ++di) {
            for (int dj = -2; dj <= 2; ++dj) {
                if (abs(di) + abs(dj) == 3) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (in_grid(ni, nj) && !vis[ni][nj]) ++cnt;
                }
            }
        }

        return cnt;
    };

    auto solve = [&](auto &&self, int r, int c, int cnt) -> bool {
        ans[r][c] = cnt;
        vis[r][c] = true;
        if (cnt == n * m) return true;
        vector<array<int, 3>> ways;
        for (int dr = -2; dr <= 2; ++dr) {
            for (int dc = -2; dc <= 2; ++dc) {
                if (abs(dr) + abs(dc) == 3) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (in_grid(nr, nc) && !vis[nr][nc]) {
                        int z = num_moves(nr, nc);
                        ways.push_back({z, nr, nc});
                    }
                }
            }
        }
        sort(ways.begin(), ways.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[0] < rhs[0];
        });
        for (auto [z, nr, nc] : ways) {
            if (self(self, nr, nc, cnt + 1)) {
                return true;
            }
        }
        vis[r][c] = false;
        return false;

    };
    assert(solve(solve, r, c, 1));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cout << ans[i][j] << " \n"[j == m - 1];
    }
    return 0;
}
