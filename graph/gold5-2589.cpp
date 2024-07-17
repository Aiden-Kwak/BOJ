#include<iostream>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

int xlen, ylen;
vector<vector<int> >map;
vector<pair<int,int> >land;
vector<int> shortest; // 특정 경로에 대한 거리의 가능성들 전부 저장
int min_way=INT_MAX;
vector<pair<int,int> >startend(2); // 시작점, 끝점 저장
vector<int> outshortway; // 경로별 최단거리 저장
// 보물은 서로간에 최단거리로 이동하는데 있어 가장 긴시간이 걸리는 육지 두곳에 있다.
// 모든 두 1위치간의 조합으로 시작,끝 만들고 dfs 최소거리 구해서 벡터에 저장.
// 벡터 민씌워서 출력

void dfs(vector<vector<int> >&map, vector<vector<bool> >&visited, vector<pair<int,int> >&startend, int dfscnt){
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    int startx=startend[0].first;
    int starty=startend[0].second;
    int endx=startend[1].first;
    int endy=startend[1].second;
    visited[startx][starty]=true;

    for(int i=0;i<4;i++){
        int nx=startx+dx[i];
        int ny=starty+dy[i];
        if(nx>=0 && nx <xlen && ny>=0 && ny<ylen && !visited[nx][ny]){
            if(nx==endx && ny==endy){
                shortest.push_back(dfscnt);
            }
            startend.push_back(make_pair(nx,ny));
            startend.push_back(make_pair(endx,endy));
            dfs(map, visited, startend, dfscnt+1);
        }
    }
}
int whatthefuck(vector<vector<int> >&map, 
                int start, int count){// 두점고를수 있게하고 dfs 파라미터에 엔드포인트 추가.
    cout << "test print(whatthe fuck!)";
    if(count==2){
        vector<vector<bool> >visited(xlen, vector<bool>(ylen, false));
        dfs(map, visited, startend, 0);
        cout << *min_element(shortest.begin(), shortest.end());
        outshortway.push_back(*min_element(shortest.begin(), shortest.end()));
        startend.clear();
        shortest.clear();
    }
    for(int i=start;i<land.size();i++){
        int x=land[i].first;
        int y=land[i].second;
        startend.push_back(make_pair(x,y));
        whatthefuck(map, i+1, count+1);
    }
    return *min_element(outshortway.begin(), outshortway.end());

}
int main(void){
    cin >> xlen >> ylen;
    map.resize(xlen, vector<int>(ylen));
    cout << "test:main(1)";
    for(int i=0;i<=xlen;i++){
        for(int j=0;j<ylen;j++){
            //cout << "i:" << i << ", j: " << j << endl;
            char word;
            cin >> word;
            if(word=='W'){
                map[i][j]=0;
            }else{
                map[i][j]=1;
                land.push_back(make_pair(i,j));
            } 
        }
    }
    cout << "test:main;(2)";
    pair<int,int>startinit(0,0);
    cout << whatthefuck(map, 0, 0) << endl;
    return 0;
}