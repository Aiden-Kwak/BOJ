#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

static int vertex, edge;

int dijkstra(vector<pair<int,int> >graph[]){
    priority_queue<pair<int,int> > pq;
    //vector<bool> visited(vertex, false);
    vector<int> dis(vertex+1, INT_MAX);
    pq.push(make_pair(1,0));
    //visited[1]=true;
    dis[1]=0;
    while(!pq.empty()){
        int current=pq.top().first;
        int price= -pq.top().second;
        pq.pop();
        for(vector<pair<int,int> >::iterator it=graph[current].begin();it!=graph[current].end();++it){
            int next=it->first;
            int next_price=it->second;
            // 다음 위치까지 가면 소먹일 여물 >=지금까지먹인 여물+다음여물
            if(dis[next]>dis[current]+next_price){
                dis[next]=dis[current]+next_price;
                pq.push(make_pair(next, -dis[next]));
            }
        }
    }
    return dis[vertex];
}

int main(void){
    cin >> vertex >> edge;
    vector<pair<int,int> > graph[vertex+1];// [0:null] [1:<2,1>] [2:<1,1>]...1은2와 연결,비용은1
    for(int i=0;i<edge;i++){
        int ai,bi,ci;
        cin >> ai >> bi >> ci;
        graph[ai].push_back(make_pair(bi,ci));
        graph[bi].push_back(make_pair(ai,ci));
    }
    cout << dijkstra(graph) << endl;
    return 0;
}