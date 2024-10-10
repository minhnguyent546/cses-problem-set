/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-10-04 10:37:34
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> left(n), right(n);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
        left[i] = (st.empty() ? -1 : st.back());
        st.emplace_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
        right[i] = (st.empty() ? n : st.back());
        st.emplace_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i] + 1;
        int r = right[i] - 1;
        assert(l <= i && i <= r);
        ans = max(ans, 1LL * arr[i] * (r - l + 1));
    }
    cout << ans << '\n';
    
    return 0;
}
