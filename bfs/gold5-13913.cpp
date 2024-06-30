#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int subin, int bro){
    vector<int> time(200001, -1);
    vector<int> parent(200001, -1); //부모로 경로를 역추적할거임.
    queue<int> q;
    q.push(subin);
    time[subin]=0;
    if(subin==bro){
        printf("%d\n", 0);
        printf("%d\n", subin);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        int next_pos[3]={node-1, node+1, node*2};
        for(int i=0;i<3;i++){
            int next=next_pos[i];
            if(next>=0&&next<=200000&&time[next]==-1){
                q.push(next);
                parent[next]=node;

                time[next]=time[node]+1;
                if(next==bro){
                    printf("%d\n", time[next]);
                    vector<int> path;
                    for(int p=next;p!=-1;p=parent[p]){
                        path.push_back(p);
                    }
                    for(int pp=path.size()-1;pp>=0;pp--){
                        printf("%d ",path[pp]);
                    }
                    cout << endl;
                    return;
                }
            }
        }
        
    }
}

int main(void){
    int subin, bro;
    cin >> subin >> bro;
    bfs(subin, bro);
    return 0;
}