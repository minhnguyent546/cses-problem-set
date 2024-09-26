/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 11:26:29
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
    int max_v = *max_element(arr.begin(), arr.end());
    vector<int> freq(max_v + 1);
    for (int value : arr) {
        freq[value]++;
    }
    for (int x = max_v; x >= 1; --x) {
        int cnt = 0;
        for (int i = x; i <= max_v && cnt < 2; i += x) {
            cnt += freq[i];
        }
        if (cnt >= 2) {
            cout << x << '\n';
            return 0;
        } 
    }
    assert(false);
    
    return 0;
}
