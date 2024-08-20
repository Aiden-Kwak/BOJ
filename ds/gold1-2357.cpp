#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

class SegmentTree {
    int n;
    vector<pair<ll, ll> > tree; // (min, max)

private:
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = make_pair(LLONG_MAX, LLONG_MIN); // Initialize with extreme values
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v].first = min(tree[v*2].first, tree[v*2+1].first);
            tree[v].second = max(tree[v*2].second, tree[v*2+1].second);
        }
    }

    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            tree[v] = make_pair(new_val, new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2, tl, tm, pos, new_val);
            else update(v*2+1, tm+1, tr, pos, new_val);
            tree[v].first = min(tree[v*2].first, tree[v*2+1].first);
            tree[v].second = max(tree[v*2].second, tree[v*2+1].second);
        }
    }

    pair<ll, ll> minmax(int v, int tl, int tr, int l, int r) {
        if (l > r) return make_pair(LLONG_MAX, LLONG_MIN);
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        pair<ll, ll> left = minmax(v*2, tl, tm, l, min(r, tm));
        pair<ll, ll> right = minmax(v*2+1, tm+1, tr, max(l, tm+1), r);
        return make_pair(min(left.first, right.first), max(left.second, right.second));
    }

public:
    SegmentTree(int size) {
        n = size;
        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h+1)) + 1;
        tree.resize(tree_size, make_pair(LLONG_MAX, LLONG_MIN));
        build(1, 1, n);
    }

    void update(int pos, ll new_val) {
        update(1, 1, n, pos, new_val);
    }

    pair<ll, ll> query(int l, int r) {
        return minmax(1, 1, n, l, r);
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num, opnum;
    cin >> num >> opnum;
    SegmentTree tree(num);
    for (int i = 1; i <= num; i++) {  // 1부터 시작
        int item;
        cin >> item;
        tree.update(i, item);  // i를 그대로 사용
    }
    for (int i = 0; i < opnum; i++) {
        int a, b;
        cin >> a >> b;
        pair<ll,ll> result = tree.query(a, b);
        cout << result.first << ' ' << result.second << '\n';  // 공백 추가
    }
    return 0;
}