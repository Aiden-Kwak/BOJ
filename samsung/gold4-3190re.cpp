#include<iostream>
#include<vector>
#include<deque>
using namespace std;
typedef vector<vector<int> > matrix;
int N,K;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
// 이거 주의: 기준은 r,c로 잡고 이동은 x,y로 시킴. 행은 y축으로 증가하니까.

// 동,남,서,북
int SNAKE_GAME(matrix &map, matrix &visited, vector<pair<int,int> > &op_pair){
    int time=0;
    deque<pair<int,int> > snake;
    snake.push_front(make_pair(1,1));
    int dir=0;
    while(1){
        time+=1;

        pair<int,int> head=snake.front();
        int x=head.first; int y=head.second;
        //next position
        int nx=x+dx[dir]; int ny=y+dy[dir];
        if(nx<1||nx>N||ny<1||ny>N||visited[nx][ny]==1){//invalid
            break;
        }

        snake.push_front(make_pair(nx,ny));
        visited[nx][ny]=1;
        if(map[nx][ny]==1){//apple
            map[nx][ny]=0;
        }else{
            visited[snake.back().first][snake.back().second]=0;
            snake.pop_back();
        }

        if(!op_pair.empty()&&op_pair.front().first==time){
            if(op_pair.front().second=='D'){
                dir=(dir+1)%4;
            }else dir=(dir+3)%4;
            op_pair.erase(op_pair.begin());
        }
    }
    return time;
} 
int main(void){
    cin >> N >> K;
    matrix map(N+1, vector<int>(N+1, 0));
    matrix visited=map;
    visited[1][1]=1;

    for(int i=1;i<=K;i++){
        int r,c;cin>>r>>c;
        map[r][c]=1;
    }

    int op;cin >> op;
    vector<pair<int,int> > op_pair;
    for(int i=0;i<op;i++){
        int X;char C; cin >> X >> C;
        op_pair.push_back(make_pair(X,C));
    }

    cout << SNAKE_GAME(map, visited, op_pair) << endl;
    return 0;
}