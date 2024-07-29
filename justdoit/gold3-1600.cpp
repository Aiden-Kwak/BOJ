#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<int> > matrix;


// 재시도할 것.
// 말, 원숭이 visited 분리? limit 명확하지 않음
// 
queue<pair<int,int> > q;
int c,r;
int min_mov;
int monkey_dx[4]={-1,1,0,0};
int monkey_dy[4]={0,0,-1,1};
int horse_dx[8]={-1,1,-1,1,-2,2,-2,2};
int horse_dy[8]={2,2,-2,-2,-1,1,1,-1};

bool isValid(int x, int y, matrix &map, matrix &visited){
    return (x>=0 && x<r && y>=0 && y<c && !map[x][y] && !visited[x][y]);
}

int monkey(matrix &map){
    int monkey_move=0;
    q.push(make_pair(0,0));
    matrix visited(r,vector<int>(c,0));
    while(!q.empty()){
        monkey_move++;
        int limit=min_mov;
        int size=q.size();
        for(int i=0;i<size;i++){
            pair<int,int> node=q.front();
            q.pop();
            for(int j=0;j<8;j++){
                int x=node.first;
                int y=node.second;
                //int m_nx=x+monkey_dx[j];
                //int m_ny=y+monkey_dy[j];
                int h_nx=x+horse_dx[j];
                int h_ny=y+horse_dy[j];
                if(isValid(h_nx,h_ny,map, visited)){
                    if(limit>=0){
                        if(h_nx==r-1 && h_ny==c-1){
                            return monkey_move;
                        }
                        limit--;
                        q.push(make_pair(h_nx,h_ny));
                        visited[h_nx][h_ny]=1;
                    }
                }else{
                    for(int m=0;m<4;m++){
                        int m_nx=x+monkey_dx[j];
                        int m_ny=y+monkey_dy[j];
                        if(isValid(m_nx,m_ny,map, visited)){
                            if(m_nx==r-1 && m_ny==c-1){
                                return monkey_move;
                            }
                            q.push(make_pair(m_nx,m_ny));
                            visited[m_nx][m_ny]=1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    cin >> min_mov;
    cin >> c >> r;
    matrix map(r, vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    if(map[0][0]==1||map[r-1][c-1]==1){
        cout << -1 << endl;
        return 0;
    }
    if(map[0][0]==0 && r==1 && c==1){
        cout << 1 << endl;
        return 0;
    }
    cout << monkey(map) << endl;
    return 0;
}