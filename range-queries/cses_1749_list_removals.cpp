/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 23:31:22
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
 
 
struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2);
        build(1, 0, n - 1);
    }
    void pull(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }
    void build(int x, int l, int r) {
        if (l == r) {
            tree[x] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);
        pull(x);
    }  
    void add(int x, int l, int r, int pos, int val) {
        if (l == r) {
            tree[x] += val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) add(x * 2, l, mid, pos, val);
        else add(x * 2 + 1, mid + 1, r, pos, val);
        pull(x);
    }
    void add(int pos, int val) {
        add(1, 0, n - 1, pos, val);
    }
    int find_first(int x, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = l + (r - l) / 2;
        if (tree[x * 2] >= k) {
            return find_first(x * 2, l, mid, k);
        }
        else return find_first(x * 2 + 1, mid + 1, r, k - tree[x * 2]);
    }
    int find_first(int k) {
        return find_first(1, 0, n - 1, k);
    }
};
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    SegTree tree(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int pos = tree.find_first(k);
        cout << arr[pos] << ' ';
        tree.add(pos, -1);
    }
    cout << '\n';
    return 0;
}
