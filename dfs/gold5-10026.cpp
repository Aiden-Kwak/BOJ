#include<iostream>
#include<vector>
using namespace std;

//적록색약은 빨강 초록 차이 못느껴
// 이게 왜 골드? 그냥 rgb각각에 대해 dfs돌린거랑, 
// RG 동일시해서 dfs 돌린 결과 각각 출력하면 될듯?

// r,g,b 3개 밖에 없으니까 그냥 rgb 각각을 1로 하는 
// 맵 새로 만들어서 탐색돌리고, 결과 더하면 될듯

void dfs(vector<vector<int> >&rgbmap, vector<vector<bool> >&visited, 
        int a, int b, int size){
    int dx[]={-1, 1, 0,0};
    int dy[]={0,0,-1,1};
    visited[a][b]=true;

    for(int i=0;i<4;i++){
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx>=0&&nx<size&&ny>=0&&ny<size&&
            !visited[nx][ny]&&rgbmap[nx][ny]==1){
            dfs(rgbmap, visited, nx,ny,size);
        }
    }
}

int good_colony(vector<vector<char> >&map, int size){
    vector<vector<int> > rmap(size, vector<int>(size,0));
    vector<vector<int> > gmap(size, vector<int>(size,0));
    vector<vector<int> > bmap(size, vector<int>(size,0));
    vector<vector<bool> > rvisited(size, vector<bool>(size,false));
    vector<vector<bool> > gvisited(size, vector<bool>(size,false));
    vector<vector<bool> > bvisited(size, vector<bool>(size,false));
    int cnt=0;

    for(int i=0;i<size;i++){
        for(int j=0;j<size; j++){
            if(map[i][j]=='R'){
                rmap[i][j]=1;
            }else if(map[i][j]=='G'){
                gmap[i][j]=1;
            }else if(map[i][j]=='B'){
                bmap[i][j]=1;
            }else{
                cout << "아악\n";
            }
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!rvisited[i][j] && rmap[i][j]==1){
                dfs(rmap, rvisited, i, j, size);
                cnt++;
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!gvisited[i][j] && gmap[i][j]==1){
                dfs(gmap, gvisited, i, j, size);
                cnt++;
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!bvisited[i][j] && bmap[i][j]==1){
                dfs(bmap, bvisited, i, j, size);
                cnt++;
            }
        }
    }
    return cnt;
}

int bad_colony(vector<vector<char> >&map, int size){ //그냥 rg묶어서 똑같이처리
    vector<vector<int> > rgmap(size, vector<int>(size,0));
    vector<vector<int> > bmap(size, vector<int>(size,0));
    vector<vector<bool> > rgvisited(size, vector<bool>(size,false));
    vector<vector<bool> > bvisited(size, vector<bool>(size,false));
    int cnt=0;

    for(int i=0;i<size;i++){
        for(int j=0;j<size; j++){
            if(map[i][j]=='R'){
                rgmap[i][j]=1;
            }else if(map[i][j]=='G'){
                rgmap[i][j]=1;
            }else if(map[i][j]=='B'){
                bmap[i][j]=1;
            }else{
                cout << "아악\n";
            }
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!rgvisited[i][j] && rgmap[i][j]==1){
                dfs(rgmap, rgvisited, i, j, size);
                cnt++;
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!bvisited[i][j] && bmap[i][j]==1){
                dfs(bmap, bvisited, i, j, size);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    int mapsize;
    cin >> mapsize;
    vector<vector<char> > map(mapsize, vector<char>(mapsize, 'x'));
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            char item;
            cin >> item;
            map[i][j]=item;
        }
    }
    printf("%d %d\n", good_colony(map, mapsize), bad_colony(map, mapsize));
    //printf("%d\n", good_colony(map, mapsize));
    return 0;
}