#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
완전이진트리, 깊이와 방문순서 주어질때,
원래의 완전이진트리 출력

예제 입력
3
1 6 4 3 5 2 7
예제 출력
3
6 2
1 4 5 7
*/
void make_tree(vector<int>&visited_order, vector<vector<int> >&tree, 
                                    int level, int start, int end){
    if(start>end) return;
    int mid=(start+end)/2;
    tree[level].push_back(visited_order[mid]);
    make_tree(visited_order, tree, level+1, start, mid-1);
    make_tree(visited_order, tree, level+1, mid+1, end);
}

int main(void){
    int depth;
    cin >> depth;
    int node=pow(2,depth)-1;
    vector<int> visited_order(node, -1);
    for(int i=0;i<node;i++){
        int building;
        cin >> building;
        visited_order[i]=building;
    }
    vector<vector<int> > tree(depth);
    make_tree(visited_order, tree, 0, 0, node-1);
    for(int i=0;i<tree.size();i++){
        for(int j=0;j<tree[i].size();j++){
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }
    return 0;

}