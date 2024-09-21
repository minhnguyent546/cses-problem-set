/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-09-20 12:39:38
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
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(i + 1);
    }
    auto cur = s.begin();
    while ((int) s.size() > 1) {
        auto next_cur = next(cur);
        if (next_cur == s.end()) {
            next_cur = s.begin();
        }   
        cout << *next_cur << ' ';
        cur = next(next_cur);
        s.erase(next_cur);
        if (cur == s.end()) {
            cur = s.begin();
        }
    }
    cout << *s.begin() <<  '\n';
    
    return 0;
}
