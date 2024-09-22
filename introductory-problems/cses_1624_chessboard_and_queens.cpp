/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:59:32
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = 8;
    int m = 8;
    vector<vector<char>> grid(n, vector<char>(m));
    char obstacle = '*';
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> grid[r][c];
        }
    }
    int ways = 0;
    vector<vector<bool>> placed(n, vector<bool>(m));
    auto in_grid = [&](int r, int c) -> bool {
        return (0 <= r && r < n && 0 <= c && c < m);
    };
    auto place = [&](auto &&self, int col) -> void {
        if (col == m) {
            ++ways;
            return;
        }
        for (int r = 0; r < n; ++r) {
            if (grid[r][col] == obstacle) continue;
            bool can_place = true;
            for (int d = -1; d <= 1 && can_place; ++d) {
                int cur_r = r + d;
                int cur_c = col - 1;
                while (in_grid(cur_r, cur_c)) {
                    if (placed[cur_r][cur_c]) {
                        can_place = false;
                        break;
                    }
                    cur_r += d;
                    cur_c -= 1;
                }
            }
            if (can_place) {
                placed[r][col] = true;
                self(self, col + 1);
                placed[r][col] = false;
            }
        }
    };
    place(place, 0);
    cout << ways << '\n';
    
    return 0;
}
