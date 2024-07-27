#include<iostream>
#include<vector>
using namespace std;

/*
3 -> 2, 1
L2-> 1, 0 ==> 1++ 0++
R1 -> 1++.

f(5) -> {5,3}
f(4) -> {3,2}
f(3) -> {2,1}
f(2) -> {1,1}
f(1) -> {1,0}
f(n)=f(n-1)+f(n-2)
*/

pair<int,int> logic(int n){ // {one, zero};
    if (n == 0) return make_pair(1, 0);
    if (n == 1) return make_pair(0, 1);

    vector<pair<int,int> > dp(n+1, make_pair(0,0));
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);

    for(int i = 2; i <= n; i++){
        int one = dp[i-1].first + dp[i-2].first;
        int zero = dp[i-1].second + dp[i-2].second;
        dp[i] = make_pair(one, zero);
    }
    return dp[n];
}

int main(void){
    int T;
    cin >> T;
    vector<pair<int,int> > answer(T);
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        pair<int,int> ans = logic(n);
        answer[i]=ans;
    }
    for(int i=0;i<T;i++){
        cout << answer[i].first << " "<< answer[i].second<<endl;
    }
    cout << endl;
    return 0;
}
