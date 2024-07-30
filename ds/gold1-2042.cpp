#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

class SegmentTree {
    int n;
    vector<ll> tree;

private:
    void build(int v, int tl, int tr) {
        if (tl == tr) tree[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) tree[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2, tl, tm, pos, new_val);
            else update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    ll sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + 
               sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

public:
    SegmentTree(int size) {
        n = size;
        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h+1)) + 1;//0 인딕스 안쓸거니까 1 증가
        tree.resize(tree_size, 0);
        build(1, 1, n);
    }

    void update(int pos, ll new_val) {
        update(1, 1, n, pos, new_val);
    }

    ll query(int l, int r) {
        return sum(1, 1, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    SegmentTree tree(N);

    for (int i = 1; i <= N; i++) {
        ll val;
        cin >> val;
        tree.update(i, val);
    }

    for (int i = 0; i < M + K; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            tree.update(b, c);
        } else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << tree.query(b, c) << '\n';
        }
    }

    return 0;
}