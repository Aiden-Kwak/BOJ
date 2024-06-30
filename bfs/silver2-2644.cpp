#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 촌수는 bfs돌려서 노드간 거리를 구하면됨.
// 나(1)와 동생(3)이라고 하면, 부모(2)를 중심으로
// 2-1, 2-3 이렇게 되있을거고 거리는2, 2촌임. 
// bfs끝나고 큐 비었는데도 목표노드 도착못했으면 -1.

int bfs(vector<vector<int> >&map,
        int num_people, int start, int end){
    queue<int> q;
    q.push(start);
    vector<bool> visited(num_people+1);
    vector<int> distance(num_people+1);
    visited[start]=true;
    distance[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==end) return distance[node];

        for(int i=0;i<map[node].size();i++){
            int next=map[node][i];
            if(!visited[next]){
                q.push(next);
                visited[next]=true;
                distance[next]=distance[node]+1;
            }
        }
    }
    return -1;
}

int main(void){
    int num_people;
    cin >> num_people;
    int target1, target2;
    cin >> target1 >> target2;
    int num_relation;
    cin >> num_relation;
    vector<vector<int> > map(num_people+1);
    for(int i=0;i<num_relation;i++){
        int father, son;
        cin >> father >> son;
        map[father].push_back(son);
        map[son].push_back(father);
    }
    int result=bfs(map, num_people, target1, target2);
    printf("%d\n", result);
}