#include<iostream>
#include<vector>
#include<queue>
#define INF 200001
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

struct compare{
    bool operator() (const Edge &e1, const Edge &e2){
        return e1.cost > e2.cost;
    }
};

int vertex, edge, start;
vector<int> dist(20001, INF);
vector<vector<Edge> > adjList(20001);
priority_queue<Edge, vector<Edge>, compare> pq;
void dijkstra(){
    pq.push(Edge(start,0)); 
    dist[start]=0;// 시작정점까지의 거리 0
    while(!pq.empty()){
        Edge cur=pq.top();
        pq.pop();
        if(dist[cur.to] < cur.cost) continue;//거리갱신 불필요
        for(int i=0;i<adjList[cur.to].size();i++){
            Edge next=adjList[cur.to][i];
            if(dist[next.to]>dist[cur.to]+next.cost){ // 현재 노드거쳐서 다른 노드 이동하는 거리가 더 짧은경우
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
    cin >> start;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjList[u].push_back(Edge(v,w));
    }
    dijkstra();
    for(int i=1;i<=vertex;i++){
        if(dist[i]==INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}


