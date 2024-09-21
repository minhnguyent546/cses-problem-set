/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 10:58:46
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long s = accumulate(arr.begin(), arr.end(), 0LL);
    if (arr[n - 1] >= s - arr[n - 1]) {
        cout << arr[n - 1] * 2 << '\n';
    }
    else {
        cout << s << '\n';
    }
    
    return 0;
}
