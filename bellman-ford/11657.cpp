#include<iostream>
#include<vector>
#define INF 60000000
typedef long long ll;
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to1, int cost1):to(to1),cost(cost1){}
};

int vertex, edge;
vector<vector<Edge> > adjList(501);
vector<ll> dist(501, INF);
bool isCycle;

void bellmanFord() {
    dist[1] = 0;
    for(int i = 1; i < vertex; ++i) {
        for(int j = 1; j <= vertex; ++j) {
            for(int k = 0; k < adjList[j].size(); k++) {
                Edge cur = adjList[j][k];
                if(dist[cur.to] > dist[j] + cur.cost && dist[j] != INF) {
                    // dist[j] != INF => 아직 탐색되지 않은 간선, 중복 방지
                    dist[cur.to] = dist[j] + cur.cost;
                }
            }
        }
    }
    for(int j = 1; j <= vertex; ++j) {
        for(int k = 0; k < adjList[j].size(); k++) {
            Edge cur = adjList[j][k];
            if(dist[cur.to] > dist[j] + cur.cost && dist[j] != INF) {
                isCycle = true; // 음수 싸이클 존재
                return;
            }
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> vertex >> edge;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjList[u].push_back(Edge(v,w));
    }
    bellmanFord();

    if(isCycle){
        cout << -1 << '\n';
    }else{
        for(int i=2;i<=vertex;i++){
            if(dist[i]==INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    return 0;
}