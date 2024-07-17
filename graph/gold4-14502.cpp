#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int> > lab;
vector<pair<int, int> > empty_spaces;
vector<pair<int, int> > virus_positions;
int max_safe_area = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<int> >& temp_lab, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx>=0 && nx<N && ny>=0 && ny<M && temp_lab[nx][ny]==0) {
            temp_lab[nx][ny] = 2;
            dfs(temp_lab, nx, ny);
        }
    }
}

int get_safe_area(const vector<vector<int> >& temp_lab) {
    int safe_area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp_lab[i][j] == 0) {
                safe_area++;
            }
        }
    }
    return safe_area;
}

// 벽 세우는 모든 경우의 수
void build_wall(int count, int start) {
    if(count == 3){
        vector<vector<int> > temp_lab = lab;
        for(int i = 0; i < virus_positions.size(); i++){
            dfs(temp_lab, virus_positions[i].first, virus_positions[i].second);
        }
        max_safe_area = max(max_safe_area, get_safe_area(temp_lab));
        return;
    }
    for(int i = start; i < empty_spaces.size(); i++){
        int x = empty_spaces[i].first;
        int y = empty_spaces[i].second;
        lab[x][y] = 1;
        build_wall(count + 1, i + 1);
        lab[x][y] = 0;
    }
}

int main(void) {
    cin >> N >> M;
    lab.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) {
                empty_spaces.push_back(make_pair(i, j));
            } else if (lab[i][j] == 2) {
                virus_positions.push_back(make_pair(i, j));
            }
        }
    }
    build_wall(0, 0);
    cout << max_safe_area << endl;
    return 0;
}
