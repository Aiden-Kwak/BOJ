#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = 0; // 초기 잔고는 0
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            tree[v] += new_val; // 기존 값에 더함
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    long long sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) 
            return tree[v];
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
             + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

public:
    SegmentTree(int size) {
        n = size;
        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h + 1));
        tree.resize(tree_size, 0);
        build(1, 1, n);
    }

    void update(int pos, long long new_val) {
        update(1, 1, n, pos, new_val);
    }

    long long query(int l, int r) {
        return sum(1, 1, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    SegmentTree st(N);

    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            long long x;
            cin >> p >> x;
            st.update(p, x);  // 수입/지출 추가
        } else if (op == 2) {
            int p, q;
            cin >> p >> q;
            cout << st.query(p, q) << "\n";  // p일부터 q일까지의 잔고 변화 출력
        }
    }

    return 0;
}