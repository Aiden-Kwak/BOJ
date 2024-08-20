#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef vector<vector<int> > matrix;
typedef long long ll;
matrix answer;
vector<ll> result;

void printAnswer(matrix v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout << v[i][j] << ' ';
        }cout << endl;
    }
}

ll operate(int sym, ll n1, ll n2){
    switch(sym){
        case 0:
            return n1+n2;
        case 1:
            return n1-n2;
        case 2:
            return n1*n2;
        case 3:
            if(n1>0) return n1/n2;
            else if(n1<0) return -1*((-1*n1)/n2);
            else return 0;
        default:
            return -100;
    }
}

void calc_answer(vector<int> &number, matrix &unique_answer){
    for(int i=0;i<unique_answer.size();i++){
        ll temp=number[0];
        for(int j=0;j<unique_answer[i].size();j++){
            temp=operate(unique_answer[i][j], temp, number[j+1]);
        }
        result.push_back(temp);
    }
}

void calc_possible(int k, int opsize, vector<int> &operation, vector<bool> &visited, vector<int> &arr){
    if(k==opsize){
        vector<int> temp;
        for(int i=0;i<opsize;i++){
            temp.push_back(arr[i]);
        }
        answer.push_back(temp);
        return;
    }
    for(int i=0;i<opsize;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[k]=operation[i];
            calc_possible(k+1, opsize, operation, visited, arr);
            visited[i]=false;
        }
    }

}

int main(void){
    int n;cin >> n;
    vector<int> number(n);
    for(int i=0;i<n;i++){
        cin >> number[i];
    }
    vector<int> operation;
    for(int i=0;i<4;i++){
        int item; cin >> item;
        for(int j=0;j<item;j++){
            operation.push_back(i);
        }
    } // 2 1 1 1 > 0 0 1 2 3

    int opsize=operation.size();
    vector<bool> visited(opsize, false);
    vector<int> arr(opsize);
    calc_possible(0, opsize, operation, visited, arr);
    set<vector<int> > s(answer.begin(), answer.end());
    matrix unique_answer(s.begin(), s.end()); // 모든 
    //printAnswer(unique_answer);
    answer.clear(); matrix().swap(answer); // 메모리 클리어
    
    calc_answer(number, unique_answer);

    ll max=-1000000000;
    ll min=1000000000;
    for(int i=0;i<result.size();i++){
        if(min>result[i]) min=result[i];
        if(max<result[i]) max=result[i];
    }
    cout << max << '\n' << min << '\n';
}