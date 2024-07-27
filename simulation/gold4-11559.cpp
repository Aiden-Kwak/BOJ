#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int ROWS=12;
const int COLS=6;
const int MIN_PUYO_GROUP=4; // 4부터 터져

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

// 주의: dfs쓰면 재귀 깊이 깊어져서 스택오버플로 발생 가능
// bfs 사용하는게 나을듯

vector<pair<int,int> > bfs(int x, int y, char color, 
                    vector<vector<char> >& map,
                    vector<vector<bool> >&visited){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    vector<pair<int, int> > group;
    group.push_back(make_pair(x,y));

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && nx<ROWS && ny>=0 && ny < COLS &&
                !visited[nx][ny] && map[nx][ny]==color){
                
                visited[nx][ny]=true;
                q.push(make_pair(nx,ny));
                group.push_back(make_pair(nx,ny));
            }
        }
    }
    return group;
}

void resetVisited(vector<vector<bool> >& visited){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            visited[i][j]=false;
        }
    }
}

/*
column을 차례로 탐색해서 뿌요를 큐에 넣고 큐에서 꺼내서 아래에서
다시 채움.

[0]
[1]
[2]
[3]

*/
void applyGravity(vector<vector<char> >&map){
    for(int col=0;col<COLS;col++){
        queue<char> q;
        for(int row=ROWS-1;row>=0;row--){//아래부터넣어
            if(map[row][col]!='.'){
                q.push(map[row][col]);
                map[row][col]='.';
            }
        }// 큐에 넣고 원래 부분을 .으로 채워.
        //그리고 여기서 칼럼을 밑에서부터 큐에든거 채우면됨.
        int row=ROWS-1; // 맨위 인덱스
        while(!q.empty()){
            map[row][col]=q.front();
            q.pop();
            row--;
        }
    }
}

int bomb(vector<vector<char> >&map, 
        vector<vector<bool> >&visited, 
        pair<int,int>& start){
    int chainCount=0;
    while(1){
        bool exploded=false;
        resetVisited(visited);
        //필드전체돌면서 터뜨릴수있는 그룹찾아
        
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(map[i][j]!='.' && !visited[i][j]){
                    vector<pair<int,int> > group=bfs(i,j,map[i][j], map, visited);
                    // 4개이상 뭉쳤으면 터쳐
                    if(group.size() >= MIN_PUYO_GROUP){
                        exploded=true;
                        for(int k=0;k<group.size();k++){
                            int x=group[k].first;
                            int y=group[k].second;
                            map[x][y]='.';
                        }
                    }
                }
            }
        }
        //터칠꺼 없으면 연쇄종료
        if(!exploded) break;
        applyGravity(map);
        chainCount++;
    }
    return chainCount;
}

int main(void){
    // 12개 줄에 필드정보, 각줄엔 6개 문자
    // R G B P Y
    vector<vector<char> > map(12, vector<char>(6, '.'));
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin >> map[i][j];
        }
    }
    pair<int,int> start=make_pair(0,0);
    vector<vector<bool> > visited(12, vector<bool>(6, false));
    int result = bomb(map, visited, start);
    cout << result << endl;
    return 0;
}