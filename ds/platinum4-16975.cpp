#include<iostream>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;

class SegmentTree{
    int n;
    vector<ll> tree;
    vector<ll> original;
private:
    // 구간 l,r에 대한 변화량 누적
    void update(int v, int start, int end, int l, int r, int new_val){
        if(l>end || r<start) return;
        if(l<=start && end<=r) {
            tree[v]+=new_val;
            return;
        }
        int mid=(start+end)/2;
        update(v*2,start,mid,l,r,new_val);
        update(v*2+1, mid+1,end,l,r,new_val);

    }
    ll query(int v, int start, int end, int x){
        if(start==end) return tree[v];
        int mid=(start+end)/2;
        if(x<=mid) return tree[v]+query(v*2, start,mid,x);
        else return tree[v]+query(v*2+1, mid+1,end,x);
    }
public:
    SegmentTree(int size, vector<ll>&array){
        n=size;
        original=array;
        int h=(int)ceil(log2(n));
        int tree_size=(1<<(h+1))+1;
        tree.resize(tree_size, 0);
    }
    void update(int l, int r, int k){
        update(1,1,n,l,r,k);
    }
    void query(int x){
        cout << query(1,1,n,x)+original[x] << '\n';
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> array(n+1);
    for(int i=1;i<=n;i++){
        cin >> array[i];
    } // 원본. 트리엔 변화량만 저장할거임
    SegmentTree tree(n, array);

    int nq;
    cin >> nq;
    for(int i=0;i<nq;i++){
        int op; cin >> op;
        switch(op){
            case 1:
                int a,b; ll k;
                cin >> a >> b >> k;
                tree.update(a,b,k);
                break;
            case 2:
                int x; cin >> x;
                tree.query(x);
                break;
        }
    }
    return 0;

}