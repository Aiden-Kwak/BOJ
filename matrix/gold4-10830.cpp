#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix operator * (const matrix & a, const matrix & b){
    int size = a.size();
    matrix res(size, vector<ll>(size));

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                res[i][j]+=a[i][k]*b[k][j];
            }
            res[i][j]%=1000;
        }
    }
    return res;
}

matrix power(matrix a, ll b){
    int size=a.size();
    matrix res(size, vector<ll>(size));

    for(int i=0;i<size;i++){
        res[i][i]=1;// 단위행렬
    }//연산에 항등원으로 쓰려고 만듦.

    while(b>0){
        if(b%2==1){
            b-=1;
            res=res*a;
        }else{
            a=a*a;
            b/=2;
        }
    }
    return res;
}

void printMatrix(const matrix& a){
    int size=a.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    int n;
    ll b;
    cin >> n >> b;

    matrix a(n, vector<ll>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    printMatrix(power(a,b));
    return 0;
}