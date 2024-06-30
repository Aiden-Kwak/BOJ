#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1차원 이동같음
// x-1, x+1, 2x 이동이 가능.
// 각 소요는 1초, 2x이동은 0초
// 1초후 이동 가능한 좌표를 전부 큐에 넣고
// bfs 돌려서 도착까지 걸리는 거리출력

int bfs(int subin, int bro) {
    if (subin == bro) return 0;

    queue<int> q;
    vector<bool> visited(200001, false);
    vector<int> time(200001, 0);

    q.push(subin);
    visited[subin] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        //0초소요 이동을 먼저 고려해야됨. 더 빠른 경로
        int next_positions[3] = {node * 2, node - 1, node + 1};

        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];
            if (next >= 0 && next <= 200000 && !visited[next]) {
                q.push(next);
                visited[next] = true;
                if(i==0){
                    time[next]=time[node];
                }else{
                    time[next] = time[node] + 1;
                }
                if (next == bro) {
                    return time[next];
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int subin, bro;
    cin >> subin >> bro;
    int result = bfs(subin, bro);
    cout << result << endl;
    return 0;
}
