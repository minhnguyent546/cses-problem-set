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

struct Info {
    long long sum;
    Info() {}
    Info(long long _sum): sum(_sum) {}
    Info operator+(const Info &other) const {
        return Info(sum + other.sum);
    }
};

struct Node {
    int val, cnt, prior;
    bool rev;
    Info info;
    Node *left, *right;
    Node() {}
    Node(int _val): val(_val), cnt(1), prior(rng()),
        rev(false), info(_val), left(nullptr), right(nullptr) {}
};
int get_cnt(Node *n) {
    return (n ? n->cnt : 0);
}
void pull(Node* &n) {
    if (!n) return;
    n->cnt = get_cnt(n->left) + get_cnt(n->right) + 1;
    n->info = Info(n->val);
    if (n->left) n->info = n->left->info + n->info;
    if (n->right) n->info = n->info + n->right->info;
}
void push(Node *n) {
    if (!n || !n->rev) return;
    swap(n->left, n->right);
    n->rev = false;
    if (n->left) n->left->rev ^= true;
    if (n->right) n->right->rev ^= true;
}
struct Treap {
    Node *root;
    Treap(): root(nullptr) {}
    pair<Node*, Node*> split(Node *treap, int pos) {
        if (!treap) return {};
        push(treap);
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
        push(l); push(r);
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
    void reverse(int u, int v) {
        auto [l, mid, r] = split(u, v);
        mid->rev ^= true;
        root = merge(merge(l, mid), r);
    }
    long long get_sum(int u, int v) {
        auto [l, mid, r] = split(u, v);
        long long res = mid->info.sum;
        root = merge(merge(l, mid), r);
        return res;
    }
    void restore(Node *treap, vector<int> &vals) {
        if (!treap) return;
        push(treap);
        restore(treap->left, vals);
        vals.emplace_back(treap->val);
        restore(treap->right, vals);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Treap treap;
    for (int i = 0; i < n; ++i) {
        treap.insert(i, arr[i]);
    }
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        --l; --r;
        if (t == 1) {
            treap.reverse(l, r);
        } else if (t == 2) {
            cout << treap.get_sum(l, r) << '\n';
        } else assert(false);
    }
    
    return 0;
}
