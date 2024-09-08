#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef vector<vector<int> > matrix;

void bfs(matrix &map, vector<bool> &visited, int root, vector<int> &parent){
    queue<int> q;
    q.push(root);
    visited[root]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<map[node].size();i++){
            int next=map[node][i];
            if(!visited[next]){
                q.push(next);
                parent[next]=node;
                visited[next]=true;
            }
        }
    }

    for(int i=2;i<=parent.size()-1;i++){
        cout << parent[i] << '\n';
    }
}
int main(void){
    int n; cin >> n;
    matrix map(n+1);
    vector<int> parent(n+1);
    for(int i=0;i<n-1;i++){
        int vi,vj;
        cin >> vi >> vj;
        map[vi].push_back(vj);
        map[vj].push_back(vi);
    }
    vector<bool> visited(n+1, false);
    bfs(map, visited, 1, parent);
}