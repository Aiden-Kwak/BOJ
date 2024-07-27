#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > matrix;

int cnt = 0;
int dx[4] = {-1, 0, 1, 0};  // 북, 동, 남, 서
int dy[4] = {0, 1, 0, -1};

void dfs(matrix &map, int x, int y, int d) {
    if (map[x][y] == 0) {  // (1)
        map[x][y] = -1;
        cnt++;
    }

    bool moved = false;
    for (int i = 0; i < 4; i++) {  // 4방향 탐색
        d = (d+3)%4;  // 반시계 회전
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (map[nx][ny] == 0) {
            dfs(map, nx, ny, d);
            moved = true;
            break;
        }
    }

    if (!moved) {  // 이동하지 못했다면 후진
        int nx_back = x - dx[d];
        int ny_back = y - dy[d];
        if (map[nx_back][ny_back] != 1) {
            dfs(map, nx_back, ny_back, d);
        }
    }
}

int robot(matrix &map, int x, int y, int d) {
    dfs(map, x, y, d);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;
    matrix map(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    cout << robot(map, x, y, d) << endl;
    return 0;
}
