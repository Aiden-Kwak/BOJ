#include<iostream>
#include<vector>
using namespace std;

int d; // d=0북, 1동, 2남, 3서
int x, y;
int n, m;
int cnt = 0;
vector<vector<int> > map;

//4방향중 0있을때 청소칸 찾을때까지 회전
void rotation() { // x, y=현위치, d=방향
    // 반시계 회전.
    for(int i = 0; i < 4; i++) {
        d = (d + 3) % 4; // 반시계 방향 회전
        if(d == 0 && y - 1 >= 0 && map[x][y - 1] == 0) {
            y -= 1; break; // 위치이동. 반복문탈출
        } else if(d == 1 && x + 1 < n && map[x + 1][y] == 0) {
            x += 1; break;
        } else if(d == 2 && y + 1 < m && map[x][y + 1] == 0) {
            y += 1; break;
        } else if(d == 3 && x - 1 >= 0 && map[x - 1][y] == 0) {
            x -= 1; break;
        }
    }

    map[x][y] = -1; //-1로 청소처리.
}

//맵 밖으로 나가는 예외처리해야해
int escape_while = 0;
void move_back() {
    if(d == 0) { //북
        if(x + 1 < n && map[x + 1][y] != 1) {
            x += 1;
        } else {
            escape_while = 1;
        }
    } else if(d == 1) { //동
        if(y - 1 >= 0 && map[x][y - 1] != 1) {
            y -= 1;
        } else {
            escape_while = 1;
        }
    } else if(d == 2) { //남
        if(x - 1 >= 0 && map[x - 1][y] != 1) {
            x -= 1;
        } else {
            escape_while = 1;
        }
    } else if(d == 3) { //서
        if(y + 1 < m && map[x][y + 1] != 1) {
            y += 1;
        } else {
            escape_while = 1;
        }
    }
}

void check_here() {
    if(map[x][y] == 0) {
        map[x][y] = -1;
        cnt += 1;
    } // 현재 위치 처리
}

int main(void) {
    cin >> n >> m;
    cin >> x >> y >> d;
    map = vector<vector<int> >(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(true) {
        check_here();

        // 주변 4칸중 청소되지 않은 빈칸이 있는 경우
        // 반시계 회전시키고 전진시킨다.
        bool found = false;
        for(int i = 0; i < 4; i++) {
            int nx = x + (i == 1) - (i == 3);
            int ny = y + (i == 2) - (i == 0);
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0) {
                found = true;
                break;
            }
        }
        if(found) {
            rotation();
        } else { // 주변 4칸중 청소되지 않는 빈칸이 없는 경우
            move_back();
            if(escape_while == 1) break;
        }
    }
    cout << cnt << endl;
    return 0;
}
