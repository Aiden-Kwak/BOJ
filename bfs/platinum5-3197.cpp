#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef vector<vector<int> > matrix;

int r,c;
queue<pair<int,int> > water_q, swan_q;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

bool isValid(int x, int y){
    return (x>=0 && x<r && y>=0 && y<c);
}

//백조를 계속 검사하면 시간초과남. 움직인 위치로부터 다시 이동시켜야함.
bool moveSwarn(matrix &map, vector<pair<int,int> > &swarn, matrix &visited){
    queue<pair<int,int> > next_q;
    while(!swan_q.empty()){
        int x = swan_q.front().first;
        int y = swan_q.front().second;
        swan_q.pop();

        if(make_pair(x,y) == swarn[1]) return true;

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isValid(nx,ny) && !visited[nx][ny]){
                visited[nx][ny] = 1;
                if(map[nx][ny] == 0) {
                    swan_q.push(make_pair(nx,ny));
                } else {
                    next_q.push(make_pair(nx,ny));
                }
            }
        }
    }
    swan_q = next_q;
    return false;
}

int bfs(matrix &map, vector<pair<int,int> > &swarn){
    int day = 0;
    matrix visited(r, vector<int>(c,0));
    swan_q.push(swarn[0]);
    visited[swarn[0].first][swarn[0].second] = 1;

    while(true){
        if(moveSwarn(map, swarn, visited)) return day;//초기상태도 검사해야해
        
        int size = water_q.size();
        for(int i = 0; i < size; i++){
            int x = water_q.front().first;
            int y = water_q.front().second;
            water_q.pop();

            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(isValid(nx,ny) && map[nx][ny] == 1){
                    map[nx][ny] = 0;
                    water_q.push(make_pair(nx,ny));
                }
            }
        }
        day++;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    matrix map(r,vector<int>(c,0));
    vector<pair<int,int> > swarn;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char item;
            cin >> item;
            if(item == '.' || item == 'L'){
                map[i][j] = 0;
                water_q.push(make_pair(i,j));
                if(item == 'L') swarn.push_back(make_pair(i,j));
            }else{
                map[i][j] = 1;    
            }
        }
    }
    cout << bfs(map, swarn) << endl;
    return 0;
}