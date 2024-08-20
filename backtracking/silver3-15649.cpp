#include<iostream>
#include<vector>

using namespace std;
int n,m;
int arr[10];
int isused[10];

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(isused[i]==0){
            arr[k]=i;
            isused[i]=1;
            func(k+1);
            isused[i]=0;
        }
    }
}
int main(void){
    cin >> n >> m;
    func(0);
    return 0;
}