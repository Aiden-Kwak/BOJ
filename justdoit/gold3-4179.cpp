#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<int> > matrix;
typedef pair<int,int> intpair;


/*
MEMO: 불 방문처리 제대로 안해서 시간초과났던거임.
endl 보다 \n이 빠르다.
*/

void testPrintMap(matrix map){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int r,c;
queue<intpair> Fire;
//queue<intpair> Space;
intpair Jihun;

bool isValid(int x, int y, matrix &visited, matrix &map){
    return (x>=0 && x<r && y>=0 && y<c && !visited[x][y] && map[x][y]!=1);
}

void testPrintQ(queue<intpair> q){
    int qsize=q.size();
    for(int i=0;i<qsize;i++){
        cout << "q: "<< q.front().first << "," << q.front().second << ' ';
        q.pop();
    }
    cout << endl;
    
}

void bfs(matrix &map){
    matrix FireVisited(r,vector<int>(c,0));
    matrix JihunVisited(r,vector<int>(c,0));
    int min=1;
    queue<intpair> q;
    q.push(Jihun);
    JihunVisited[Jihun.first][Jihun.second]=1;
    while(!q.empty()){
        min++;
        int FireSize=Fire.size();
        for(int i=0;i<FireSize;i++){
            intpair node=Fire.front();
            Fire.pop();
            int Fx=node.first; int Fy=node.second;
            FireVisited[Fx][Fy]=1;
            for(int i=0;i<4;i++){
                int nx=Fx+dx[i];
                int ny=Fy+dy[i];
                if(isValid(nx,ny,FireVisited, map)){
                    Fire.push(make_pair(nx,ny));
                    map[nx][ny]=-2;
                    FireVisited[nx][ny]=1;
                };   
            }
        }// 매분 화재상황 업데이트

        int qsize=q.size();
        for(int ii=0;ii<qsize;ii++){
            intpair JNode=q.front();
            q.pop();
            int Jx=JNode.first;
            int Jy=JNode.second;
            //cout << "check: "<< Jx << "," << Jy << endl;
            for(int i=0;i<4;i++){
                int nxx=Jx+dx[i];
                int nyy=Jy+dy[i];
                //cout << "check2: "<< dx[i] << "," << dy[i] << endl;
                //cout << "(x,y): " << nxx << ',' << nyy << endl;
                if(isValid(nxx,nyy,JihunVisited,map) && map[nxx][nyy]!=-2){
                    //cout << "도달: " << nxx << ',' << nyy << endl;
                    if(nxx==0 || nyy==0 || nxx==r-1 || nyy==c-1){
                        cout << min << '\n';
                        return;
                    }
                    q.push(make_pair(nxx,nyy));
                    JihunVisited[nxx][nyy]=1;
                    //testPrintQ(q);
                }
            }
        }
        //testPrintMap(map);
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    matrix map(r, vector<int>(c,0));
    // #:1, .: 0, J: -1, F:-2
    // 탈출지점: [0,x], [x,0], [r-1,x], [x, c-1]
    // 매 분마다 화재상황 업데이트해서 맵을 변동해야해
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char item;
            cin >> item;
            if(item=='#'){
                map[i][j]=1;
            }else if(item=='F'){
                map[i][j]=-2;
                Fire.push(make_pair(i,j));
            }else if(item=='J'){
                Jihun=make_pair(i,j);
                map[i][j]=-1;
            }else{
                map[i][j]=0;
                //Space.push(make_pair(i,j));
            }
        }
    }
    if(Jihun.first==0||Jihun.first==r-1||Jihun.second==0||Jihun.second==c-1){
        cout << "1\n";
        return 0;
    }
    //testPrintMap(map);
    bfs(map);
    return 0;
}
