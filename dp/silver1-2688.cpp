#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

/*
2:
00, 01, 02 .. 09 > 10
11, 12, 13, .. 19 > 9
22, 23, .. 29 > 8
..
99 > 1
>> 1+2+ ..+ 10 = 55

3:
000, 001, 002 .. 009
0

2자리 > 55개 > 10+9+..1
3자리 > 
000-9, 011-9, 022-9, .. 099 > (10+9+..1)
111-9, 122-9, 133-9,...199 > (9+..1)
..
888-9, 899 : 2+1
999: 1

4자리 > 
0000-9, 000

>>
10+9+..1
(10+9+..1) + (9+8+..1) + .. + (2+1) + 1
dp[i][j]는 i자리수에서 마지막 숫자가 j인경우의수
dp[i][j]=dp[i-1][j]+dp[i][j-1] 
최종결과는 dp[n][0]+dp[n][1]+...+dp[n][9]

우선 dp 테이블을 그리면서 규칙을 찾는게 중요할 듯
*/

int main(void){
    int t;
    cin >> t;
    vector<ll> ans(t, 0);

    for(int i=0;i<t;i++){
        int n; // 자리수
        cin >> n;

        vector<vector<long long> > dp(n+1, vector<ll>(10, 0));
        // dp[0]={0}; //안써. 문법 안돼서 포문돌리자
        for(int ii=0;ii<=9;ii++){
            dp[0][ii]=0;
        }
        //dp[1]={1};
        for(int ii=0;ii<=9;ii++){
            dp[1][ii]=1;
        }
        // dp[n][0]=1;
        for(int ii=2;ii<=n;ii++){
            dp[ii][0]=1;
        }

        for(int ii=2;ii<=n;ii++){
            for(int j=1;j<=9;j++){
                dp[ii][j]=dp[ii-1][j]+dp[ii][j-1];
            }
        }

        int temp=0;
        for(int ii=0;ii<=9;ii++){
            temp=temp+dp[n][ii];
        }
        ans[i]=temp;
    }

    for(int i=0;i<t;i++){
        cout << ans[i]<<endl;
    }
    return 0;
    
}