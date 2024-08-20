#include<iostream>
#include<cmath>
#include<vector>
typedef long long ll;
#define NUM 1000000007
using namespace std;

class SegmentTree{
    int n;
    vector<ll> tree;
private:
    void build(int v, int tl, int tr){
        if(tl==tr) tree[v]=1;
        else{
            int tm=(tl+tr)/2;
            build(v*2, tl,tm);
            build(v*2+1, tm+1, tr);
            tree[v]=(tree[v*2]*tree[v*2+1])%NUM;
        }
    }
    void update(int v, int tl, int tr, int pos, ll new_val){
        if(tl==tr) tree[v]=new_val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm) update(v*2, tl, tm, pos, new_val);
            else update(v*2+1, tm+1, tr, pos, new_val);
            tree[v]=(tree[v*2]*tree[v*2+1])%NUM;
        }
    }
    ll mult(int v, int tl, int tr, int l, int r){
        if(l>r) return 1; // invalid; 주의: 0 반환시 전체가 0 돼.
        if(tl==l && tr==r){
            return tree[v];
        }
        else{
            int tm=(tl+tr)/2;
            return (mult(v*2, tl, tm, l, min(tm,r))*mult(v*2+1, tm+1, tr, max(tm+1,l), r))%NUM;
        }
    }

public:
    SegmentTree(int size){
        n=size;
        int h=(int)ceil(log2(n));
        int tree_size=(1<<(h+1))+1;
        tree.resize(tree_size);
        build(1,1,n);
    }
    void update(int pos, ll new_val){
        update(1,1,n,pos,new_val);
    }
    void query(int l, int r){
        cout << mult(1,1,n,l,r) << '\n';
    }

};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; int nupdate, nmult;
    cin >> n >> nupdate >> nmult;

    SegmentTree tree(n);
    for(int i=1;i<=n;i++){
        int item; cin >> item;
        tree.update(i,item);
    }
    for(int i=0;i<nupdate+nmult;i++){
        int op; cin >> op;
        switch(op){
            case 1:
                int b,c; cin >> b >>c;
                tree.update(b,c);
                break;
            case 2:
                int bb,cc; cin >> bb >> cc;
                tree.query(bb,cc);
                break;
        }
    }
    return 0;
}