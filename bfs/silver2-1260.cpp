#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> >& adj_list, vector<bool>& visited, int start) {
    visited[start] = true;
    printf("%d ", start);
    for (int i = 0; i < adj_list[start].size(); i++) {
        int next = adj_list[start][i];
        if (!visited[next]) {
            dfs(adj_list, visited, next);
        }
    }
}

void bfs(vector<vector<int> >& adj_list, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start); // (1)
    visited[start] = true; // (1)

    while (!q.empty()) { // (2) 큐가 빌때까지
        int node = q.front(); // 큐 첫번쨰정점
        q.pop(); // 첫번째 정점 큐에서 제거
        printf("%d ", node);

        for (int i = 0; i < adj_list[node].size(); i++) {
            int next = adj_list[node][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void) {
    int n_vertex, n_edge, start;
    cin >> n_vertex >> n_edge >> start;
    vector<vector<int> > adj_list(n_vertex + 1);
    for (int i = 0; i < n_edge; i++) {
        int v_i, v_j;
        cin >> v_i >> v_j;
        adj_list[v_i].push_back(v_j);
        adj_list[v_j].push_back(v_i);
    }

    // 인접 리스트 정렬
    for (int i = 1; i <= n_vertex; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    // DFS
    vector<bool> visited_dfs(n_vertex + 1, false);
    dfs(adj_list, visited_dfs, start);
    cout << endl;

    // BFS
    vector<bool> visited_bfs(n_vertex + 1, false);
    bfs(adj_list, visited_bfs, start);
    cout << endl;

    return 0;
}
