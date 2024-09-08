#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef vector<vector<int> > matrix;
int n,ss; 

void calc_possible(int k, int serial_len, vector<int> &number, vector<bool> &visited, vector<int> &arr, matrix &answer){
    if(k==serial_len){
        vector<int> temp;
        for(int i=0;i<serial_len;i++){
            temp.push_back(arr[i]);
        }
        answer.push_back(temp);
        return;
    }
    for(int i=(k>0 ? visited.size()-1 : 0);i<number.size();i++){
        if(!visited[i]){
            bool valid=true;
            for(int j=0;j<i;j++){
                if(visited[j]) valid=false;
            }
            if(!valid) continue;
            visited[i]=true;
            arr[k]=number[i];
            calc_possible(k+1, serial_len, number, visited, arr, answer);
            visited[i]=false;
        }
    }
}


void printAnswer(matrix v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout << v[i][j] << ' ';
        }cout << endl;
    }
}
int main(void){
    cin >> n >> ss;
    vector<int> number(n);
    for(int i=0;i<n;i++){
        cin >> number[i];
    }

    int cnt=0; // cnt for s
    for(int i=1;i<=number.size();i++){
        int serial_len=i;
        vector<int> arr(serial_len);
        vector<bool> visited(serial_len, false);
        matrix answer;
        calc_possible(0, serial_len ,number, visited, arr, answer);
        //unordered_set<vector<int> > s(answer.begin(), answer.end());
        //matrix unique_answer(s.begin(), s.end());
        printAnswer(answer);
        for(int j=0;j<answer.size();j++){
            int sum=0;
            for(int k=0;k<answer[0].size();k++){
                sum+=answer[j][k];
            }
            if(sum==ss) cnt+=1;
        }
    }
    cout << cnt << '\n';
}