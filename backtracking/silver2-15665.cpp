#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n,m;
vector<vector<int> > answer;

void printAnswer(vector<vector<int> > v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout << v[i][j] << ' ';
        }cout << '\n';
    }
}
void func(int k, vector<int> &vinput, vector<int> &arr){
    if(k==m){
        vector<int> temp;
        for(int i=0;i<m;i++){
            temp.push_back(arr[i]);
        }
        answer.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        arr[k]=vinput[i];
        func(k+1, vinput, arr);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> vinput(n);
    vector<int> arr(m);
    for(int i=0;i<n;i++){
        cin >> vinput[i];
    }
    sort(vinput.begin(), vinput.end());
    func(0,vinput, arr);
    set<vector<int> > s(answer.begin(), answer.end());
    vector<vector<int> > unique_answer(s.begin(), s.end());
    printAnswer(unique_answer);
    return 0;
}