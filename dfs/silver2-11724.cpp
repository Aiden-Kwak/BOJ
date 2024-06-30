#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, const vector<vector<int> >& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        int next = adj[v][i];
        if (!visited[next]) {
            dfs(next, adj, visited);
        }
    }
}

int connected_component(int v, const vector<vector<int> >& adj) {
    vector<bool> visited(v + 1, false);
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            cnt++;
        }
    }
    return cnt;
}

int main(void) {
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int> > adj_list(vertex + 1);
    for (int i = 0; i < edge; i++) {
        int e_i, e_j;
        cin >> e_i >> e_j;
        adj_list[e_i].push_back(e_j);
        adj_list[e_j].push_back(e_i);
    }
    cout << connected_component(vertex, adj_list) << endl;
    return 0;
}


/*
#include<iostream>
#include<vector>

using namespace std;

//인접리스트 전체를 순회하면서 dfs를 돌려. 
//한번돌때 재귀로 쭉 돌리니까 한사이클에 연결요소 쭉 돎. 
//못돌면 끊겨있는거임. 그러니까 사이클마다 카운트 해주면 
// 연결요소 개수확인가능.

void dfs(int v, const vector<vector<int> >& adj, vector<bool>& visited){
    visited[v]=true;
    for(int i=1;i < adj[v].size();i++){
        if(adj[v][i]==1 && !visited[i]){
            dfs(i,adj,visited);
        }
    }
}

int connected_component(int v, const vector<vector<int> >& adj){
    vector<bool> visited(v+1, false);
    int cnt=0;
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            dfs(i, adj, visited);
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    int vertex, edge;
    scanf("%d %d", &vertex, &edge);
    vector<vector<int> > adj_list(vertex+1, vector<int>(vertex+1, 0));
    for(int i=0;i<edge;i++){
        int e_i, e_j;
        scanf("%d %d", &e_i, &e_j);
        adj_list[e_i][e_j]=1;
        adj_list[e_j][e_i]=1;
    }

    printf("%d\n", connected_component(vertex, adj_list));
    return 0;
}
*/