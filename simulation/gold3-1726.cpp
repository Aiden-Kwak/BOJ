#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef vector<vector<int> > matrix;
typedef pair<pair<int,int>, int> mytuple;

int r,c;//세로,가로
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int operation=0;
//{1,2,3,4}=동서남북

struct Robot{
public:
    int x,y,d;
};

bool isValid(int x, int y, matrix visited){
    return (x>=0 && x<r && y>=0 && y<c && !visited[x][y]);
}

int cnt=0;
void goK(mytuple &start, mytuple end, matrix &map, matrix &visited, int k){
    int x=start.first.first;
    int y=start.first.second;
    int d=start.second;
    int next_x=x+dx[d]*k;
    int next_y=y+dy[d]*k;
    if(isValid(next_x, next_y, visited)){
        visited[next_x][next_y]=1;
        start=make_pair(make_pair(next_x,next_y),d);
        cnt++;
    }
}

void turn(int d)

void bfs(mytuple &start, mytuple end, matrix &map){
    queue<mytuple> q;
    matrix visited(r,vector<int>(c,0));
    q.push(start);
    while(!q.empty()){
        mytuple node=q.front();
        int x=node.first.first;
        int y=node.first.second;
        int d=node.second;
        q.pop();
        for(int i=)
        // 회전횟수로 직진 회숫도 계산 가능할 것 같음

    }

}

int main(void){;
    cin >> r >> c;
    Robot robot;
    matrix map(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    int s_i,s_j,s_d, e_i,e_j,e_d;
    cin >> s_i >> s_j >> s_d;
    cin >> e_i >> e_j >> e_d;
    mytuple start=make_pair(make_pair(s_i,s_j),s_d);
    mytuple end=make_pair(make_pair(e_i,e_j),e_d);
    bfs(start, end, map);
}