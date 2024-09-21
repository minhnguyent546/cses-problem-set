/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-07-16 13:30:34
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long right = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > right + 1) {
            break;
        }
        right += arr[i];
    }
    cout << right + 1 << '\n';
    return 0;
}
