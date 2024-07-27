#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > matrix;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

bool isValid(matrix &visited, int h, int w, int y, int x){
    return (x>=0 && x<w && y>=0 && y<h && visited[y][x]==0);
}

void dfs(matrix &map, matrix &visited, int y, int x, int h, int w){
    visited[y][x]=1;
    for(int i=0;i<8;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(isValid(visited, h,w,ny,nx) && map[ny][nx]){
            dfs(map,visited,ny,nx,h,w);
        }
    }
}

void cntIsland(matrix &map, matrix &visited, int &island, int h, int w){
    island=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j] && !visited[i][j]){
                dfs(map, visited, i,j,h,w);
                island++;
            }
        }
    }
}

void testPrintMap(matrix map){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    vector<int> answersheet;
    while(1){
        int w,h;
        cin >> w >> h;
        if(w==0 && h==0) break;
        matrix map(h, vector<int>(w));
        matrix visited(h, vector<int>(w,0));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        int island=0;
        cntIsland(map, visited, island, h,w);
        answersheet.push_back(island);
    }
    for(int i=0;i<answersheet.size();i++){
        cout << answersheet[i] << endl;
    }
    return 0;
}