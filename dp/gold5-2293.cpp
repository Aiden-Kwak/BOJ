#include<iostream>
#include<vector>
using namespace std;
/*
n종류 동전
가치의 합이 k.
경우의수 계산.
1,2,5 로 10만드는 경우?
1 10개

현재 동전 v[i]를 사용헤 금액 j를 만든다
=> j-v[i]를 만드는 방법의 수를 더해야해

dp[n]_new=dp[n]_prev+dp[n-현재사용한 동전종류]
*/
int dp[10001];
int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=k;j++){
            dp[j]+=dp[j-v[i]];
        }
    }
    cout << dp[k]<<endl;
    return 0;

}