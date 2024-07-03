#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool vis[500001][2];

int sum(int n) {
    return n * (n + 1) / 2;
}

int bfs(int subin, int bro) {
    queue<pair<int, int> > q;
    q.push(make_pair(subin, 0));
    vis[subin][0] = true;

    int i = 0;
    while (true) {
        int size = q.size();
        int bro_pos = bro + sum(i);

        if (bro_pos < 0 || bro_pos > 500000) {
            return -1;
        }

        while (size--) {
            pair<int, int> cur = q.front();
            q.pop();

            if (cur.first == bro_pos || vis[bro_pos][i % 2] == true) {
                return i;
            }

            int next_positions[3] = {cur.first - 1, cur.first + 1, cur.first * 2};
            for (int j = 0; j < 3; ++j) {
                int next_pos = next_positions[j];
                if (next_pos >= 0 && next_pos <= 500000 && !vis[next_pos][(cur.second + 1) % 2]) {
                    vis[next_pos][(cur.second + 1) % 2] = true;
                    q.push(make_pair(next_pos, cur.second + 1));
                }
            }
        }
        i++;
    }

    return -1;
}

int main() {
    int subin, bro;
    cin >> subin >> bro;
    int result = bfs(subin, bro);
    cout << result << endl;
    return 0;
}
