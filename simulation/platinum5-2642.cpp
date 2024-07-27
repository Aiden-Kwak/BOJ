#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > matrix;
typedef vector<vector<bool> > bool_matrix;
#define SIZE 6
/*
MEMO:
1) 시작면에서 인접면 방향과 같은 방향으로 두번 이동할 수 있다면 마주하는 한쌍이다.
2) 이동거리가 2인 면을 단 하나만 탐색할 수 있어야한다.
*/
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

//visited조건을 재정의
// 방문&0이면 처리, 페어만들어진부분 처리
bool_matrix visited(SIZE, vector<bool>(SIZE, false));
vector<bool> number(7, false);//페어처리된건 처리. 0부분은 넘길거라 true처리


//같은 i 아래에서 동작했는지 세야함. 어케셈?
vector<bool> checki_m(4, false);
bool isItCheckTwice(int i){
    if(checki_m[i]==true) return true;
} 

// checki_m 언제 다시 초기화해야할까
void dfs(matrix &map, pair<int,int> &start){
    int dir[4]={0,1,2,3};// 동서남북: 같은방향으로 두번이동가능여부 체크
    int start_x=start.first;
    int start_y=start.second;
    vector<pair<int,int> > paired_plane;
    pair<int,int> temp=make_pair(map[start_x][start_y], 0);//0은 임시
    for(int i=0;i<4;i++){// 0-> -1,0(W),  1-> 1,0(E), 2-> 0,-1(N), 3->0,1(S)
        int nx=start_x+dx[i];
        int ny=start_y+dy[i];
        if(map[nx][ny]!=0 && !number[map[nx][ny]] && !isItCheckTwice(i)){//전개도상이고, 아직 페어안된거.
            pair<int,int> next = make_pair(nx,ny);
            dfs(map, next);
        }else if(isItCheckTwice(i)){
            temp.second=map[nx][ny];
            paired_plane.push_back(temp);
        }
        checki_m[i]=true;
    }

}

int main(void){
    number[0]=true;
    matrix map(SIZE, vector<int>(SIZE, 0));
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            cin >> map[i][j];
        }
    }
    // 시작지점 생성
    pair<int,int> start;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(map[i][j]!=0) start=make_pair(i,j);
        }
    }
    dfs(map, start);

}