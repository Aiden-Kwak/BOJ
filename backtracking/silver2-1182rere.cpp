#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef vector<vector<int> > matrix;

int n, s;
int cnt=0;
void possible(int k, int sum, vector<int> &INPUT_ARR){
    if(k==n){
        if(sum==s) cnt++;
        return;
    }
    possible(k+1, sum+INPUT_ARR[k], INPUT_ARR); // k원소 포함
    possible(k+1, sum, INPUT_ARR);// k원소 미포함
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n>> s;
    vector<int> INPUT_ARR(n);
    for(int i=0;i<n;i++){
        cin >> INPUT_ARR[i];
    }

    possible(0,0,INPUT_ARR);

    if(s==0) cnt-=1; // 합0일때 공집합제거

    cout << cnt << '\n';
    return 0;
}