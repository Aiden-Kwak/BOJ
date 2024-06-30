#include<iostream>
#include<vector>

using namespace std;
//cin,cout이 scanf보다 느려.

int move(int n, int m, int num_app, const vector<int>& pos_app){
    int l=1;
    int r=m;
    int cnt=0;
    //0번배열 안쓸거야
    for(int i=1;i<=num_app;i++){
        int pos=pos_app[i];
        if (l<=pos && pos<=r) continue;
        else if(pos<l){
            cnt+=(l-pos);
            l=pos;
            r=l+m-1;
        }
        else{//pos>r
            cnt+=(pos-r);
            l+=(pos-r);
            r=pos;
        }
    }
    return cnt;
}

int main(void){
    int N,M;//screen, basket
    scanf("%d %d",&N,&M);

    int num_apple;
    scanf("%d", &num_apple);

    vector<int> pos_apple(num_apple+1);
    for(int i=1;i<=num_apple;i++){
        scanf("%d",&pos_apple[i]);
    }
    printf("%d\n", move(N,M,num_apple, pos_apple));
}
// 떨어질 위치에 이미 바구니 있으면 안움직여도됨
// 가장 가까운 바구니를 움직여야됨.
//!!!! 이거 바구니가 여러개 각각 따로 움직이는게 아니라 한덩이로 움직임.