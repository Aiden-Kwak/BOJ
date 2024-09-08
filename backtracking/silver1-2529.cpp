#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef vector<vector<int> > matrix;

//matrix MAT;
vector<int> mat1d;
vector<int> visited(10,0);//sync with numbers

bool checkValid(int op, int l, int r){
    switch(op){
        case 0:
            return (l<r)?true:false;
        case 1:
            return (l>r)?true:false;
        default:
            return false;
    }
}

void possible(int k, vector<int> &op, vector<int> &numbers, vector<int> &ans){
    int m=op.size()+1;
    int ansSize=ans.size();
    int theAnswer=0;
    if(k==m){
        mat1d.push_back(theAnswer);
        return;
    }
    for(int i=0;i<numbers.size();i++){
        if(k==0||!visited[i]&&checkValid(op[k-1],ans[k-1],numbers[i])){
            visited[i]=true;
            ans.push_back(numbers[i]);
            theAnswer+=pow(10,ansSize-k)*numbers[i];
            possible(k+1, op, numbers, ans);
            visited[i]=false;
            ans.pop_back();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;cin>>k;
    vector<int> op(k); // <:0, >:1
    for(int i=0;i<k;i++){
        cin >> op[i];
    }
    vector<int> numbers(10);
    for(int i=0;i<=9;i++){
        numbers[i]=i;
    }
    vector<int> ans(k+1,0); // [1][2][3] -> 0인덱스: pos(10,(k-0)), 1: pos(10, (k-1))
    possible(0, op, numbers, ans);

    for(int i=0;i<mat1d.size();i++){
        cout << mat1d[i] << '\n';
    }
    return 0;
}