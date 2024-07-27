#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 105
using namespace std;
int N,K,L,Value,Yes=0;
vector<int> Code[MAX]; // 이거 2차원 선언임.
// : int arr[3] 이 int 요소 3개짜리 배열임을 생각해보자
// vector<int> 가 MAX개 있는 2차원 배열임.

vector<int> Fail(vector<int> &SubCode){
    vector<int> Pi(SubCode.size());
    // Pi[0]은 어차피 필요가 없어. 안됨
    for(int i=1,j=0;i<SubCode.size();i++){
        // 현재까지 일치한 접두사의 길이j를 얻는다
        while(j>0&&SubCode[i]!=SubCode[j]) j=Pi[j-1];
        if(SubCode[i]==SubCode[j]) Pi[i]=++j;
    }
    return Pi;
}

vector<int> Fail(vector<int> &SubCode){
    vector<int> Pi(SubCode.size());
    for(int i=1,j=0;i<SubCode.size();i++){
        while(j>0&&SubCode[i]!=SubCode[j]){
            j=Pi[j-1];
        }
        if(SubCode[i]==SubCode[j]) Pi[i]=++j;
    }
}


int KMP(vector<int> &Code, vector<int> &SubCode){
    // Code에 SubCode가 있으면 1을 반환
    vector<int> Pi = Fail(SubCode);
    //서브코드와 본코드를 앞에서부터 비교할건데
    //비교후 틀렸을때 i를 1개씩 밀지 않고
    //Fail값을 기준으로 옮길거임.
    for(int i=0,j=0;i<Code.size();i++){
        while(j>0&&Code[i]!=SubCode[j]) j=Pi[j-1];
        if(Code[i]==SubCode[j]){
            // 돌면서 앞쪽은 이미 같은부분이 있는걸 확인
            // 뒤쪽이 같고 지금까지 비교해온 영역이
            // 서브코드 길이와 같으면 서브코드가 코드에
            // 있는거임. 
            if(j==SubCode.size()-1) return 1;
            else j++;
        }
    }
    return 0;
}

int main(void){
    for(int i=0;i<N;i++){
        cin >> L;
        for(int j=0;j<L;j++){
            cin >> Value;
            Code[i].push_back(Value);
        }
    }
    // [0,1,2,3,4,5,6,7,8,9]
    // 여기서 3길이의 코드를 전부 추출
    // 그럼 전체 순회횟수는 처음 [0,1,2] + [0~9]-[0,1,2]
    // 전체길이-코드길이+1
    for(int i=0;i<Code[0].size()-K+1;i++){
        vector<int> SubCode(K);
        for(int j=0;j<K;j++){
            SubCode[j]=Code[0][i+j];
            // 코드만들기. 맨위에걸로 만들어서 아래다 비교함.
        }
        int Check=1;
        for(int j=1;j<N;j++){
            vector<int> RevCode=Code[j];
            reverse(RevCode.begin(), RevCode.end());
            // 서브코드가 없거나 뒤집힌 서브코드가 없으면 
            // 체크는 0
            if(!KMP(Code[i], SubCode) && !KMP(RevCode, SubCode)) Check=0;
        }
        if(Check) Yes=1;//서브코드가 있으면 Yes=1;
    }
    if(Yes) cout << "YES" << endl;
    else cout << "NO" << endl;
}