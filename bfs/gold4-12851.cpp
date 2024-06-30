#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int subin, int bro) {
    queue<int> q;
    vector<int> time(200001, -1);
    vector<int> count(200001, 0);
    
    q.push(subin);
    time[subin] = 0;
    count[subin] = 1; //각 위치 도달하는 경로수 기록용

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int next_positions[3] = {node - 1, node + 1, node * 2};

        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];
            if (next >= 0 && next <= 200000) {
                if (time[next] == -1) {
                    q.push(next);
                    time[next] = time[node] + 1;
                    count[next] = count[node];
                } else if (time[next] == time[node] + 1) {
                    count[next] += count[node];
                }
            }
        }
    }

    cout << time[bro] << "\n" << count[bro] << "\n";
}

int main(void) {
    int subin, bro;
    cin >> subin >> bro;
    bfs(subin, bro);
    return 0;
}
