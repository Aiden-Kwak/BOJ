#include<iostream>
#include<vector>

// 상하좌우의 경우가 인점경우
// 덩어리 개수를 구하면 되는듯

// 2차원배열만들고 쭉 순회하면서, 1이면 dfs돌리고, 
// 1차원 배열에 인접 영역 전부 표시. cnt+=1
// 2차원배열 순회중 1차원배열에 있는 곳 또는, 0을 만나면 패스
// cnt return.
using namespace std;
int dfs(const vector<vector<int> >& ground, 
        int x, int y,
        vector<vector<bool> >& visited){
    int n=ground.size();
    int m=ground[0].size();
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};

    visited[x][y]=true;
    
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m &&
            ground[nx][ny]==1 && !visited[nx][ny]){
            dfs(ground, nx, ny, visited);
        }
    }
    return 0;
}

int cnt_cluster(vector<vector<int> >& ground){
    int n=ground.size();
    int m=ground[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m,false));
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ground[i][j]==1 && !visited[i][j]){
                dfs(ground, i, j, visited);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    int test_case_num;
    scanf("%d", &test_case_num);
    int answer[test_case_num];
    for(int i=0;i<test_case_num;i++){
        int row, column, cabbage;
        scanf("%d %d %d", &row, &column, &cabbage);
        vector<vector<int> > ground(row, vector<int>(column, 0));
        for(int j=0;j<cabbage;j++){
            int c_i, c_j;
            scanf("%d %d", &c_i, &c_j);
            ground[c_i][c_j]=1;
        }
        answer[i]=cnt_cluster(ground);
    }
    for(int i=0;i<test_case_num;i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}