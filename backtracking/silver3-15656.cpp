#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int arr[10];

void func(int k, vector<int> &input_arr){
    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        //if((k==0 || arr[k-1]<input_arr[i])){
            arr[k]=input_arr[i];
            func(k+1, input_arr);
        //}
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> input_arr(n);
    for(int i=0;i<n;i++){
        cin >> input_arr[i];
    }
    sort(input_arr.begin(), input_arr.end());
    func(0,input_arr);
    return 0;
}