/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 11:44:44
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
    vector<int> left(n, -1);
    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && arr[stack.back()] >= arr[i]) stack.pop_back();
        if (!stack.empty()) left[i] = stack.back();
        stack.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << left[i] + 1 << " \n"[i == n - 1];
    }
    
    return 0;
}
