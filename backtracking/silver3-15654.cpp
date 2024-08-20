#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int arr[10];

void testPrint(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void func(int k, vector<int>&farr, vector<bool>&visited){
    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            arr[k]=farr[i];
            visited[i]=1;
            func(k+1, farr, visited);
            visited[i]=0;
        }
    }

}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> input_arr(n);
    vector<bool> visited(n,0);
    for(int i=0;i<n;i++){
        cin >> input_arr[i];
    }
    sort(input_arr.begin(), input_arr.end());
    func(0,input_arr, visited);
    return 0;
}