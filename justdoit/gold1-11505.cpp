#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef long long ll;
#define NUM 1000000007

class SegmentTree{
private:
    int n;
    vector<ll> tree;
    void build(int v, int tl, int tr){
        if(tl==tr) tree[v]=1;  // 곱셈의 항등원은 1입니다.
        else{
            int tm=(tl+tr)/2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v]=(tree[v*2] * tree[v*2+1]) % NUM;
        }
    }

    void update(int v, int tl, int tr, int pos, int new_val){
        if(tl==tr) tree[v]=new_val;
        else{
            int tm=(tl+tr)/2;
            if(pos <= tm) update(v*2, tl, tm, pos, new_val);
            else update(v*2+1, tm+1, tr, pos, new_val);
            tree[v]=(tree[v*2] * tree[v*2+1]) % NUM;
        }
    }

    ll mult(int v, int tl, int tr, int l, int r){
        if(l > r) return 1;  // 곱셈의 항등원은 1입니다.
        if(l==tl && r==tr) return tree[v];
        int tm=(tl+tr)/2;
        return (mult(v*2, tl, tm, l, min(r, tm)) * 
                mult(v*2+1, tm+1, tr, max(l, tm+1), r)) % NUM;
    }
public:
    SegmentTree(int size){
        n=size;
        int h=(int)ceil(log2(n));
        int tree_size=(1<< (h+1));
        tree.resize(tree_size, 1);
        build(1,1,n);
    }
    void update(int pos, ll new_val){
        update(1,1,n,pos,new_val);
    }
    ll query(int l, int r){
        return mult(1,1,n,l,r);
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, nswitch, nmult;
    cin >> n >> nswitch >> nmult;
    SegmentTree tree(n);
    for(int i=1;i<=n;i++){
        int val;
        cin >> val;
        tree.update(i, val);
    }
    //cout << nswitch+nmult << '\n';
    for(int i=0;i<nswitch+nmult;i++){
        int op;
        cin >> op;
        switch(op){
            case 1:
                {
                    int b,c;
                    cin >> b >> c;
                    tree.update(b,c);
                }
                break;
            case 2:
                {
                    int b,c;
                    cin >> b >> c;
                    cout << tree.query(b,c) << '\n';
                }
                break;
        }
    }
    return 0;
}