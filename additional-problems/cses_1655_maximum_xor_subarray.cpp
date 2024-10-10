/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-09-16 15:07:16
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

#define has(mask, i) ((mask >> i) & 1)

const int BIT = 31;
struct Vertex {
    int next[2];
    Vertex() {
        memset(next, -1, sizeof next);
    }
};
struct Trie {
    vector<Vertex> trie;
    Trie() {
        trie.emplace_back();
    }

    void insert(int val) {
        int i = 0;
        for (int bit = BIT - 1; bit >= 0; --bit) {
            int j = ((val >> bit) & 1);
            if (trie[i].next[j] == -1) {
                trie[i].next[j] = (int) trie.size();
                trie.emplace_back();
            }
            i = trie[i].next[j];
        }
    }

    int walk(int val) {
        int ret = 0;
        int i = 0;
        for (int bit = BIT - 1; bit >= 0; --bit) {
            int j = ((val >> bit) & 1);
            if (trie[i].next[1 - j] != -1) {
                ret += (1 << bit);
                i = trie[i].next[1 - j];
            } else {
                assert(trie[i].next[j] != -1);
                i = trie[i].next[j];
            }
        }
        return ret;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Trie trie;
    trie.insert(0);
    int ans = 0;
    for (int i = 0, cur = 0; i < n; ++i) {
        cur ^= arr[i];
        ans = max(ans, trie.walk(cur));
        trie.insert(cur);
    }
    cout << ans << '\n';
    
    return 0;
}
