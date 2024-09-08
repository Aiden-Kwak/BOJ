#include<iostream>
#include<vector>
#include<queue>
#define INF 10000000001
using namespace std;
typedef long long ll;

struct Edge{
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

struct compare{
    bool operator() (Edge &e1, Edge &e2){
        return e1.cost > e2.cost;
    }
};

int vertex, edge;
int start, terminal;
vector<vector<Edge> > adjList(100001);
vector<ll> dist(100001, INF); 
priority_queue<Edge, vector<Edge>, compare> pq;

void dijkstra(){
    pq.push(Edge(start, 0));
    dist[start]=0;
    while(!pq.empty()){
        Edge cur=pq.top();
        pq.pop();
        if(dist[cur.to] < cur.cost) continue;
        for(int i=0;i<adjList[cur.to].size();i++){
            Edge next=adjList[cur.to][i];
            if(dist[next.to] > dist[cur.to]+next.cost){
                dist[next.to]=dist[cur.to]+next.cost;
                pq.push(Edge(next.to, dist[next.to]));      
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
    cin >> start >> terminal;
    dijkstra();
    cout << dist[terminal] << '\n';
    return 0;
}