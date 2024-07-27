#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
//using ll=long long;

/*
costmap:
   R  G  B [cost]
0 26 40 83
1 49 60 57
2 13 89 99
[house num]
*/
/*
bool isValid(tuple<char,char,char> t){
    return ((get<0>(t)!=get<1>(t)) && (get<1>(t)!=get<2>(t)));
}

vector<tuple<char,char,char> > everyRGB(int n){
    vector<tuple<char, char, char> > validTuples;
    vector<char> colors={'R', 'G', 'B'};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                tuple<char,char,char> t=make_tuple(i,j,k);
                if(isValid(t)) validTuples.push_back(t);
            }
        }
    }
    return validTuples;
}

int main(void){
    int n;
    cin >> n;
    vector<vector<int> > costmap(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> costmap[i][j];
        }
    }
    vector<tuple<char, char, char> > RGB;
    RGB=everyRGB(n);

}*/

int main(void){
    int n;
    cin >> n;
    vector<vector<int> > dp(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> dp[i][j];
        }
    }

    for(int i=1;i<n;i++){
        dp[i][0]+=min(dp[i-1][1], dp[i-1][2]);
        dp[i][1]+=min(dp[i-1][0], dp[i-1][2]);
        dp[i][2]+=min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min(dp[n-1][0],min(dp[n-1][1], dp[n-1][2])) << endl;
    return 0;
}