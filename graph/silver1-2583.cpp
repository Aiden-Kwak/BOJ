#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef vector<vector<int> > matrix;

int c,r, k;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cnt_s;
void dfs(const matrix &map, matrix &visited, int y, int x){
    visited[y][x]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx <int(map[0].size()) && ny>=0 && ny<int(map.size()) && !map[ny][nx] && !visited[ny][nx]){
            cnt_s+=1;
            dfs(map, visited, ny, nx);
        }
    }

}

int cnt_area=0;
vector<int> calc(const matrix &map, matrix &visited){
    vector<int> temp;
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(!map[i][j] && !visited[i][j]){
                cnt_s=1;
                dfs(map, visited, i, j);
                cnt_area+=1;
                temp.push_back(cnt_s);
            }
        }
    }
    sort(temp.begin(), temp.end());
    return temp;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> r >> k;
    matrix map(r, vector<int>(c, 0));
    matrix visited=map;
    for(int i=0;i<k;i++){
        int vi,vj,vii,vjj;
        cin >> vi >> vj >> vii >>vjj;
        for(int colori=vi;colori<vii;colori++){
            for(int colorj=vj;colorj<vjj;colorj++){
                map[colori][colorj]=1;
            }
        }
    }
    
    
    vector<int> answer= calc(map, visited);
    cout << cnt_area << '\n';
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << ' ';
    }cout << '\n';
    return 0;
}