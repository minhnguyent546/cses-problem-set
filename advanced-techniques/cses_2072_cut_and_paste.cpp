/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-08-10 20:35:00
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

struct Node {
    int val, cnt, prior;
    Node *left, *right;
    Node() {}
    Node(int _val): val(_val), cnt(1), prior(rng()), left(nullptr), right(nullptr) {}
};
int get_cnt(Node *n) {
    return (n ? n->cnt : 0);
}
void pull(Node* &n) {
    if (!n) return;
    n->cnt = get_cnt(n->left) + get_cnt(n->right) + 1;
}
struct Treap {
    Node *root;
    Treap(): root(nullptr) {}
    pair<Node*, Node*> split(Node *treap, int pos) {
        if (!treap) return {};
        int idx = get_cnt(treap->left);
        if (idx <= pos) {
            auto pr = split(treap->right, pos - idx - 1);
            treap->right = pr.first;
            pull(treap);
            return {treap, pr.second};
        }
        else {
            auto pl = split(treap->left, pos);
            treap->left = pl.second;
            pull(treap);
            return {pl.first, treap};
        }
    }
    tuple<Node*, Node*, Node*> split(int u, int v) {
        auto [l, rem] = split(root, u - 1);
        auto [mid, r] = split(rem, v - u);
        return {l, mid, r};
    }
    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        if (l->prior < r->prior) {
            l->right = merge(l->right, r);
            pull(l);
            return l;
        }
        else {
            r->left = merge(l, r->left);
            pull(r);
            return r;
        }
    }
    void insert(int pos, int val) {
        auto [l, r] = split(root, pos - 1);
        root = merge(merge(l, new Node(val)), r);
    }
    void move_to_the_end(int u, int v) {
        auto [l, mid, r] = split(u, v);
        root = merge(merge(l, r), mid);
    }
    void restore(Node *treap, vector<int> &vals) {
        if (!treap) return;
        restore(treap->left, vals);
        vals.emplace_back(treap->val);
        restore(treap->right, vals);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    Treap treap;
    for (int i = 0; i < n; ++i) {
        treap.insert(i, i);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        treap.move_to_the_end(u, v);
    }
    vector<int> indices;
    treap.restore(treap.root, indices);
    for (int i = 0; i < n; ++i) {
        cout << s[indices[i]];
    }
    cout << '\n';
    
    return 0;
}
