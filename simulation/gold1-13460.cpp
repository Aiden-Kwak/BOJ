#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<char> > matrix;
typedef pair<int,int> marble;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int r,c;

void testPrintMap(const matrix &map){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            cout << map[i][j] << ' ';
        }cout << '\n';
    }
    cout << endl;
}

bool isValid(int x, int y){
    return (x>=0 && x<r && y>=0 && y<c);
}

void gravity(matrix &map, int d, marble &Rxy, marble &Bxy){
    int k=0;
    while(1){
        k++;
        int Rx=Rxy.first; int Ry=Rxy.second;
        int Bx=Bxy.first; int By=Bxy.second;

        int Rnx=Rx+dx[d]*k;
        int Rny=Ry+dy[d]*k;
        int Bnx=Bx+dx[d]*k;
        int Bny=By+dy[d]*k;

        if(isValid(Rnx,Rny)&&isValid(Bnx,Bny)){
            char Ritem=map[Rnx][Rny];
            char Bitem=map[Bnx][Bny];
            if(Ritem=='.'){
            map[Rx][Ry]='.';
            map[Rnx][Rny]='R';
            Rxy=make_pair(Rnx,Rny);
            }
            if(Bitem=='.'){
                map[Bx][By]='.';
                map[Bnx][Bny]='B';
                Bxy=make_pair(Bnx,Bny);
            }
            if(Ritem=='#' && Bitem=='#'){
                break;
            }
        }    
    }
}

int dfs(matrix &map, marble &Rxy, marble &Bxy, int &move){
    int Rx=Rxy.first; int Ry=Rxy.second;
    if(map[Rx][Ry]=='O'){
        return move;
    }
    for(int i=0;i<4;i++){
        int nx=Rx+dx[i];
        int ny=Ry+dy[i];
        if(map[nx][ny]=='.'){
            gravity(map,i,Rxy,Bxy);
            testPrintMap(map);
            move++;
            dfs(map,Rxy,Bxy,move);
        }
    }
    return -1;
}

int main(void){
    cin >> r >> c;
    matrix map(r, vector<char>(c,'.'));
    marble Rxy;
    marble Bxy;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j]=='R'){
                Rxy=make_pair(i,j);
            }
            if(map[i][j]=='B'){
                Bxy=make_pair(i,j);
            }
        }
    }
    testPrintMap(map);
    int move=0;
    cout << dfs(map, Rxy, Bxy, move) << '\n';
    return 0;
}