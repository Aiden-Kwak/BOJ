#include<iostream>
using namespace std;

int arr[10]={0,};
bool is_used[10];
int n,m;

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }cout << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(is_used[i]==0 && (i>arr[k-1] || k==0)){
            arr[k]=i;
            is_used[i]=1;
            func(k+1);
            is_used[i]=0;
        }
    }
}

int main(void){
    cin >> n >> m;
    func(0);
    return 0;
}