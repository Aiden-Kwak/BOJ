#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int> > complete_op;

void printAnswer(vector<vector<int> > &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }
}

void calc_possible(int k, vector<int> &oparr, int oparrsize,
                vector<int> &temparr, vector<bool> &visited){
    vector<int> temp;
    if(k==oparrsize){
        for(int i=0;i<oparrsize;i++){
            temp.push_back(temparr[i]);
        }
        complete_op.push_back(temp);
        return;
    }
    for(int i=0;i<oparrsize;i++){
        if(!visited[i]){
            temparr[k]=oparr[i];
            visited[i]=1;
            calc_possible(k+1, oparr, oparrsize, temparr, visited);
            visited[i]=0;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> operation(4);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int number_op=0;
    for(int i=0;i<4;i++){
        cin >> operation[i];
        number_op+=operation[i];
    }// 2 1 1 1 (number_op)

    /*
    0: +, 1: -, 2: *, 3: /
    */
    vector<int> oparr;
    int oparr_size=oparr.size();
    for(int i=0;i<4;i++){
        for(int j=0;j<operation[i];j++){
            oparr.push_back(i);
        }
    }// 2 1 1 1 -> 0 0 1 2 3(oparr)
    vector<bool> visited(oparr_size, false);
    vector<int> temparr(oparr_size);

    calc_possible(0, oparr, oparr_size, temparr, visited);
    set<vector<int> > s(complete_op.begin(), complete_op.end());
    vector<vector<int> > unique_arr(s.begin(), s.end());
    printAnswer(unique_arr);
    return 0;
}