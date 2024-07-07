#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int start, int vertex, vector<pair<int, int>> graph[]) {
    vector<int> dist(vertex + 1, INT_MAX);  // 거리 저장
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start)); // 거리, 노드

    while (!pq.empty()) {
        int current_weight = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (vector<pair<int, int>>::iterator it = graph[current].begin(); it != graph[current].end(); ++it) {
            int next = it->first;
            int next_weight = it->second;
            if (dist[next] > dist[current] + next_weight) {
                dist[next] = dist[current] + next_weight;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    return dist;
}

int main() {
    int nvertex, nedge;
    cin >> nvertex >> nedge;
    vector<pair<int, int>> graph[nvertex + 1];

    for (int i = 0; i < nedge; i++) {
        int va, vb, length;
        cin >> va >> vb >> length;
        graph[va].push_back(make_pair(vb, length));
        graph[vb].push_back(make_pair(va, length));
    }

    int must_va, must_vb;
    cin >> must_va >> must_vb;

    // 1 -> A, 1 -> B, A -> B, A -> N, B -> N
    vector<int> dist_from_start = dijkstra(1, nvertex, graph);
    vector<int> dist_from_A = dijkstra(must_va, nvertex, graph);
    vector<int> dist_from_B = dijkstra(must_vb, nvertex, graph);

    int way1 = dist_from_start[must_va] + dist_from_A[must_vb] + dist_from_B[nvertex];
    int way2 = dist_from_start[must_vb] + dist_from_B[must_va] + dist_from_A[nvertex];

    int result = min(way1, way2);

    if (dist_from_start[must_va] == INT_MAX || dist_from_start[must_vb] == INT_MAX ||
        dist_from_A[must_vb] == INT_MAX || dist_from_A[nvertex] == INT_MAX ||
        dist_from_B[must_va] == INT_MAX || dist_from_B[nvertex] == INT_MAX) {
        cout << "-1" << endl;
        /*
        1에서 a 경로 없음, 1에서 b경로 없음
        a에서 b경로 없음, a에서 end경로 없음, b에서 a경로 없음, b에서 end경로 없음
        */
    } else {
        cout << result << endl;
    }

    return 0;
}
