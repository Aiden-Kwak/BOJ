#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1(0) 2(1) 4(1) 7(0) 11(0) 16(1) 22(1) 29(0) 37(0) 46(1) 56(1) 홀홀짝짝홀홀짝짝
// 굳이? 그냥 동생 경로를 미리 넣어버리면 문제가 있나: 동생이 먼저 5000000에 도착하는 경우체크.
// 수빈이 먼저 도착해야 자리에서 진동대기시킬수있음.
// 300000 0 케이스? 엇갈리면서 -1뜰거같긴함. 어떤 케이스로 분류시켜야하나. 3만이 위치임.
// bro_hist[2]=2초일때 위치.
// bro_hist[i]=300000, => i초일때 위치가 300000이다. 
// 교훈: 정의를 명확히하자 병신아.

// 수빈 최초 도달시점이 짝수초면 진동결과 도착하는 시간은 짝수초임. 동생 도착이 홀수초면 못만나.
// 반대로 홀수면 홀수. 

int exist_list(int item, vector<int> target){
    for(int i=0;i<target.size();i++){
        if(item==target[i]) return i;
    }
    return -1;
}

int bfs(int subin, int bro){
    queue<int> q;
    vector<int> time(500000, -1);
    time[subin]=0;
    // exception
    if(subin==bro) return 0;
    if(subin>=500000 || bro>=500000) return -1;

    //bro_hist
    vector<int> bro_hist(500000, -1);
    int btime=0;
    bro_hist[0]=bro;
    int bro_pos=bro;
    while(bro_pos<=500000){
        btime+=1;
        bro_pos+=btime;
        bro_hist[btime]=bro_pos;
    }

    q.push(subin);
    int time_elapse=0;
    while(!q.empty()){
        time_elapse++;
        for(int i=0;i<q.size();i++){
            int node=q.front();
            q.pop();
            int check_bro=exist_list(node, bro_hist);
            if(check_bro!=-1){
                if(time_elapse%2==0 && check_bro%2==0){
                    return check_bro;
                } else if(time_elapse%2==1 && check_bro%2==1){
                    return check_bro;
                } else{
                    return -1;
                }
            }
            int possible[3]={node-1, node+1, node*2};
            for(int j=0;j<3;j++){
                int next_pos=possible[j];
                if(next_pos>=0&&next_pos<=500000&&time[next_pos]==-1){
                    time[next_pos]=time_elapse;
                    q.push(next_pos);
                }
            }
        }
    }
    return -1;
}

int main(void){
    int subin, bro;
    cin >> subin >> bro;
    int result = bfs(subin, bro);
    cout << result << endl;
    //cout << check_bro_list(subin, bro) << endl;
    return 0;
}