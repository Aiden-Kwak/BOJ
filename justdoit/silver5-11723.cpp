#include<iostream>
#include<cstring>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str="";
    int M, x;
    int S=0; //비트
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> str;
        if(str=="add"){
            cin >> x;
            S |= (1<<x);
        }else if(str=="remove"){
            cin >> x;
            S &= ~(1<<x);
            /*
            00010
            00000
            */
        }else if(str=="check"){
            cin >> x;
            if(S & (1<<x)){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }else if(str=="toggle"){
            cin >> x;
            if(S & (1<<x)){
                S &= ~(1<<x);
            }else{
                S |= (1<<x);
            }
        }else if(str=="all"){
            S = (1<<21)-1;
            // 1<<21 : 100000000000000
            // 1빼면 다 1됨
        }else{
            S=0;
        }
    }
    return 0;
}

/*
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str="";
    int M,x;
    int arr[21]={0};//1~20까지 존재여부만 체크하면되니까

    cin >> M;
    for(int i=0;i<M;i++){
        cin >> str;
        if(str=="add"){
            cin >> x;
            if(arr[x]==0){
                arr[x]=1;
            }
        }
        else if(str=="remove"){
            cin >> x;
            if(arr[x]==1){
                arr[x]=0;
            }
        }
        else if(str=="check"){
            cin >> x;
            if(arr[x]==1){
                cout << 1 << endl;
            }else cout << 0 << endl;
        }
        else if(str=="toggle"){
            cin >> x;
            if(arr[x]==1){
                arr[x]=0;
            }else arr[x]=1;
        }
        else if(str=="all"){
            memset(arr, 1, sizeof(arr));
        }
        else if(str=="empty"){
            memset(arr, 0, sizeof(arr));
        }
    }

    return 0;
}
*/