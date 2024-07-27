#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix operator * (const matrix &A, const matrix &B){
    int a_n = A.size(); // A의 행
    int a_m = A[0].size(); // A의 열
    int b_n = B.size(); // B의 행
    int b_m = B[0].size(); // B의 열

    matrix res(a_n, vector<ll>(b_m, 0));

    for (int i = 0; i < a_n; ++i) {
        for (int j = 0; j < b_m; ++j) {
            for (int k = 0; k < a_m; ++k) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return res;
}

void printMatrix(const matrix &m){
    int a = m.size();
    int b = m[0].size();
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    int a_n, a_m;
    cin >> a_n >> a_m;
    matrix A(a_n, vector<ll>(a_m));
    for(int i = 0; i < a_n; i++){
        for(int j = 0; j < a_m; j++){
            cin >> A[i][j];
        }
    }

    int b_n, b_m;
    cin >> b_n >> b_m;
    matrix B(b_n, vector<ll>(b_m));
    for(int i = 0; i < b_n; i++){
        for(int j = 0; j < b_m; j++){
            cin >> B[i][j];
        }
    }

    matrix result = A * B;
    printMatrix(result);
    return 0;
}
