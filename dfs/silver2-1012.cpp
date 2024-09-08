#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<int> > matrix;

int m,n,k;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(const matrix &map, matrix &visited, int x, int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&map[nx][ny]==1){
            dfs(map, visited, nx,ny);
        }
    }
}

void bfs(const matrix &map, matrix &visited, int x, int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        int x=node.first;
        int y=node.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&map[nx][ny]==1){
                visited[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    } 
}

int get_colony(const matrix &map){
    matrix visited(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(!visited[i][j]&&map[i][j]==1){
                //dfs(map, visited, i,j);
                bfs(map, visited, i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    vector<int> answer(t);
    for(int i=0;i<t;i++){
        cin>>m>>n>>k;
        matrix map(n, vector<int>(m,0));
        for(int j=0;j<k;j++){
            int x,y;cin>>x>>y;
            map[y][x]=1;
        }
        int colony=get_colony(map);
        answer[i]=colony;
    }
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
    return 0;
}