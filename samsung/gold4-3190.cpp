#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<int> > matrix;

int N; 

bool isValid(pair<int,int>&head, bool start){
    int x=head.first;int y=head.second;
    if(start==false) return true;
    return !( x<1 || y<1 ||x>N || y>N);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int line; cin >> line;
    matrix map(N+1, vector<int>(N+1,0)); // no 0,0 index
    matrix visited = map; visited[1][1]=1; // worm init
    queue<pair<int,int> > snake;
    snake.push(make_pair(1,1));

    for(int i=0;i<line;i++){
        int r,c;
        cin >> r >> c;
        map[r][c]=1; // apple
    }
    int L; cin >> L;

    queue<pair<int,char> > op;
    for(int i=0;i<L;i++){
        int X; char C;
        cin >> X >> C;
        op.push(make_pair(X,C));
    }
    
    int time=-1;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    // 초기 오른쪽방향 dx[0],dy[0]
    int dir=0;
    pair<int,int> head=make_pair(1,1);
    bool start=0;
    while(isValid(head,start)){
        start=1;
        time+=1;
        pair<int,char> op_pair=op.front();
        int op_time=op_pair.first;
        char op_dir=op_pair.second;
        int x=head.first;
        int y=head.second;

        if(time==op_time){
            if(op_dir=='L'){
                dir=(dir+3)%4;
            }else dir=(dir+1)%4;
        } // 방향전환
        cout << "dir: "<< dir << endl;
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(visited[nx][ny]==1) break; // isValid에서 따로 뽑았음.
        visited[nx][ny]=1; // add snake position // 여기서 미리 넣어서 문제
        snake.push(make_pair(nx,ny));
        //head 재정의
        head=make_pair(nx,ny);
        
        if(map[nx][ny]!=1){
            visited[snake.front().first][snake.front().second]=0;//remove tail
            snake.pop();
        }else map[nx][ny]=0;

        cout << "valid:" << isValid(head, start) << endl;
        cout << head.first << ',' << head.second << endl;
        cout << visited[head.first][head.second] << endl;
    }
    printf("%d\n", time+1);
    return 0;
}