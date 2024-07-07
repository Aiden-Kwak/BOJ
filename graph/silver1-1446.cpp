#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
첫째 줄에 지름길의 개수 N과 고속도로의 길이 D가 주어진다. N은 12 이하인 양의 정수이고, 
D는 10,000보다 작거나 같은 자연수이다. 다음 N개의 줄에 지름길의 시작 위치, 도착 위치, 지름길의 길이가 주어진다. 
모든 위치와 길이는 10,000보다 작거나 같은 음이 아닌 정수이다. 지름길의 시작 위치는 도착 위치보다 작다.
운전해야하는 거리의 최소값 출력.
*/

int dijkstra(int len_highway, vector<pair<int, int> > graph[]) {
    vector<int> dist(len_highway + 1, INT_MAX);
    priority_queue<pair<int, int> > pq;

    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_dist = -pq.top().first;
        pq.pop();

        //if (current_dist > dist[current]) continue;

        for (vector<pair<int, int> >::iterator it = graph[current].begin(); it != graph[current].end(); ++it) {
            int next_node = it->first;
            int weight = it->second;

            if (dist[next_node] > dist[current] + weight) {
                dist[next_node] = dist[current] + weight;
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }

        // 고속도로 기본 경로도 고려
        if (current + 1 <= len_highway && dist[current + 1] > dist[current] + 1) {
            dist[current + 1] = dist[current] + 1;
            pq.push(make_pair(-dist[current + 1], current + 1));
        }
    }

    return dist[len_highway];
}

int main(void) {
    int num_fast, len_highway;
    cin >> num_fast >> len_highway;
    vector<pair<int, int> > graph[10001];  // 고속도로 길이 최대값으로 설정

    for (int i = 0; i < num_fast; i++) {
        int start, end, length;
        cin >> start >> end >> length;
        if (end <= len_highway) {  // 지름길의 끝이 고속도로 길이보다 작거나 같을 때만 추가
            graph[start].push_back(make_pair(end, length));
        }
    }

    cout << dijkstra(len_highway, graph) << endl;
    return 0;
}
