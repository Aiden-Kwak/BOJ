#include<iostream>
#include<vector>

using namespace std;

bool dfs(int current, int target, vector<vector<int> >& adj, vector<bool>& visited) {
    if (current == target) return true;
    visited[current] = true;

    for (int i = 0; i < adj[current].size(); i++) {
        int next = adj[current][i];
        if (!visited[next]) {
            if (next == target || dfs(next, target, adj, visited)) return true;
        }
    }
    return false;
}

void print_out(vector<vector<int> >& adj) {
    int len = adj.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) {
                printf("0 ");
                continue;
            }
            vector<bool> visited(len, false);
            if (dfs(i, j, adj, visited)) printf("%d ", 1);
            else printf("%d ", 0);
        }
        printf("\n");
    }
}

int main(void) {
    int num_node, item;
    cin >> num_node;
    vector<vector<int> > adj_list(num_node); 
    for (int i = 0; i < num_node; i++) {
        for (int j = 0; j < num_node; j++) {
            cin >> item;
            if (item == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    print_out(adj_list);
    return 0;
}
