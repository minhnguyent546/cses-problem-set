/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 12:09:30
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max_v = *max_element(arr.begin(), arr.end());
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    long long l = max_v, r = sum;
    auto good = [&](long long sum) -> bool {
        int group_cnt = 0;
        for (int i = 0; i < n; ++i) {
            long long cur = arr[i];
            int j = i;
            while (j + 1 < n && cur + arr[j + 1] <= sum) {
                cur += arr[j + 1];
                ++j;
            }
            ++group_cnt;
            i = j;
        }
        return group_cnt <= k;
    };
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (good(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
    
    return 0;
}
