/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-10-07 20:20:20
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int N = 8;
double dp[N][N][N][N], next_dp[N][N][N][N], empty_prob[N][N];
int num_ways[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    cout.precision(6); cout << fixed;
    int k;
    cin >> k;

    int n = N;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            dp[r][c][r][c] = 1.0;
        }
    }

    const int dirs = 4;
    int dr[] = {-1, 0, 0, 1};
    int dc[] = {0, -1, 1, 0};
    auto in_grid = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    };
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int t = 0; t < dirs; ++t) {
                int nr = r + dr[t];
                int nc = c + dc[t];
                if (in_grid(nr, nc)) ++num_ways[r][c];
            }
        }
    }
    for (int z = 0; z < k; ++z) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int y = 0; y < n; ++y) {
                    for (int x = 0; x < n; ++x) {
                        next_dp[r][c][y][x] = 0.0;
                        for (int t = 0; t < dirs; ++t) {
                            int ny = y + dr[t];
                            int nx = x + dc[t];
                            if (in_grid(ny, nx)) {
                                next_dp[r][c][y][x] += dp[r][c][ny][nx] / num_ways[ny][nx];
                            }
                        }
                    }
                }
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int y = 0; y < n; ++y) {
                    for (int x = 0; x < n; ++x) {
                        dp[r][c][y][x] = next_dp[r][c][y][x];
                    }
                }
            }
        }
    }

    double ans = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            empty_prob[r][c] = 1.0;
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    empty_prob[y][x] *= (1 - dp[r][c][y][x]);
                }
            }
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            ans += empty_prob[r][c];
        }
    }
    cout << ans << '\n';
    
    return 0;
}

/*
dp[r][c][y][x] = probability of robot at (r, c) move to (y, x) after k steps
*/
