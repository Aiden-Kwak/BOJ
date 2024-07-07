#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<int> dijkstra(int start, int vertex, vector<pair<int, int> > graph[]) {
    vector<int> dist(vertex + 1, INT_MAX);
    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current_weight = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (vector<pair<int, int> >::iterator it = graph[current].begin(); it != graph[current].end(); ++it) {
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
    int start;
    cin >> start;
    vector<pair<int, int> > graph[nvertex + 1];

    for (int i = 0; i < nedge; i++) {
        int vstart, vend, weight;
        cin >> vstart >> vend >> weight;
        graph[vstart].push_back(make_pair(vend, weight));
    }

    vector<int> dist = dijkstra(start, nvertex, graph);
    for (int i = 1; i <= nvertex; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
