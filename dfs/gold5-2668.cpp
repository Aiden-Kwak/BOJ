#include<iostream>
#include<vector>
#include<set>

// 2*n table
// 첫째줄과 둘째줄의 집합이 일치하는 최대 개수?
// set이용하면 될거같은데 그냥 경우의수 다 돌려도 
// 복잡도 안높을거같은데
// 아 dfs맞다 1,3이면 이게 집합 일치하려면 다음건 3,x여야함.
// 쭉 이어가면됨. x가 visited면 끝난거임. 
// i, value가 같고, 앞서 돌린 내용에 없으면 추가해야해
// dfs돌릴때 value값이 겹치지 않게 방문처리잘해야해


/*
둘째줄의 노드가 첫째줄의 노드를 가리키는 그래프 생각.
1: [2,3]
2: []
3: [1]
4: [6]
5: [4,5]
6: [7]
7: []
사이클들을 찾아서 구성하는 노드들을 합쳐준다.
*/
using namespace std;


void dfs(vector<vector<int> >&adj_list, vector<bool>&visited, int item){

}

void output(vector<vector<int> >&adj_list, int size){
    vector<bool> visited(size+1, false);
    int cnt=0; // num of cycle.
    set<int> out_cycle; // 나중에 출력용
    for(int i=1;i<=size;i++){
        set<int> cycle;
        visited[i]=true;
        cycle.insert(i);
        for(int j=0;j<adj_list[0].size();j++){
            if(!visited[adj_list[i][j]]){
                cnt++;
                cycle.insert(i);
                cycle.insert(adj_list[i][j]);
                dfs(adj_list, visited, adj_list[i][j]);
            }
        }

    }
}
int main(void){
    int size;
    cin >> size;
    vector<vector<int> > adj_list(size+1); // dont use 0 node.
    for(int i=1;i<=size;i++){
        int item;
        cin >> item;
        adj_list[i].push_back(item);
        adj_list[item].push_back(i);
    }
    output(adj_list, size);
    return 0;
}
