#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int> > answer;
void printAnswer(vector<vector<int> >&answer){
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[0].size();j++){
            cout << answer[i][j] << ' ';
        }cout << '\n';
    }
}
void func(int k, const vector<int>& input_arr, vector<int>& current, int m, vector<bool>& visited) {
    if (k == m) {
        vector<int> temp(m);
        for (int i = 0; i < m; i++) {
            temp[i]=current[i];
        }
        answer.push_back(temp);
        return;
    }
    for (int i = 0; i < input_arr.size(); i++) {
        if(!visited[i] && (k==0||current[k-1]<=input_arr[i])){
            visited[i]=1;
            current[k] = input_arr[i];
            func(k + 1, input_arr, current, m, visited);
            visited[i]=0;

        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> input_arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> input_arr[i];
    }

    vector<int> current(m);
    sort(input_arr.begin(), input_arr.end());
    vector<bool> visited(m);
    func(0, input_arr, current, m, visited);
    set<vector<int> > s(answer.begin(), answer.end());
    vector<vector<int> > unique_answer(s.begin(), s.end());
    printAnswer(unique_answer);
    return 0;
}