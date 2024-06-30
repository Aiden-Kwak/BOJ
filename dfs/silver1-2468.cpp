#include<iostream>
#include<vector>
#include<set> //set쓰면 자동 정렬/중복제거됨.
using namespace std;


// 안전한 영역의 최대개수 출력
// 최대 높이를 우선 확인하고, 1부터 최대 높이까지 
// 반복문돌려서 안전영역 개수확인

// 맵을 우선 입력값대로 만들고, 안전높이가 만약 5면
// 5이하는 0, 5이상을 1로 하는 맵 새로 만들어서 dfs.
// 이걸 반복돌리면 아마 n*O(n^2) > O(n^3)
// 시간초과날거같음. dfs를 O(n)으로 구현할 수 있도록.
// 이거 복잡도 조졌는데 가능한가?
// 69%에서 패일. > 비 안오는경우 고려안함.

void dfs(vector<vector<int> >&bmap, vector<vector<bool> >&visited, 
        int mapsize, int a, int b){
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    visited[a][b]=true;

    for(int i=0;i<4;i++){
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx>=0&&nx<mapsize&&ny>=0&&ny<mapsize&&
            !visited[nx][ny]&&bmap[nx][ny]==1){
                dfs(bmap, visited,mapsize,nx,ny);
            }
    }
}

int cnt_colony(vector<vector<int> >&map, vector<int>&sorted_map_item, int map_size){
    vector<int> num_safe_region;

    for(int safe=0;safe<sorted_map_item.size();safe++){
        vector<vector<int> > binary_map(map_size, vector<int>(map_size, 0));
        int safe_height=sorted_map_item[safe];
        vector<vector<bool> >visited(map_size, vector<bool>(map_size, false));
        int cnt=0;
        // generate binary map
        for(int i=0;i<map_size;i++){
            for(int j=0;j<map_size;j++){
                if(safe_height<map[i][j]){
                    binary_map[i][j]=1;
                }
            }
        }
        // traverse whole map and apply dfs
        for(int i=0;i<map_size;i++){
            for(int j=0;j<map_size;j++){
                if(binary_map[i][j]==1 && !visited[i][j]){
                    cnt++;
                    dfs(binary_map, visited, map_size, i, j);
                }
            }
        }
        num_safe_region.push_back(cnt);
    }

    int max=0;
    for(int i=0;i<num_safe_region.size();i++){
        if(num_safe_region[i]>max) max=num_safe_region[i];
    }

    return max;
}

int main(void){
    int map_size;
    cin >> map_size;
    vector<vector<int> > map(map_size, vector<int>(map_size, 0));
    set<int> unique_map;
    for(int i=0;i<map_size;i++){
        for(int j=0;j<map_size;j++){
            int item;
            cin >> item;
            map[i][j]=item;
            unique_map.insert(item); 
        }
    }
    vector<int> sorted_map_item(unique_map.begin(), unique_map.end());
    
    //비가 아예 안오는 경우도 고려해야돼. 맨앞에 0 데이터 추가.
    sorted_map_item.insert(sorted_map_item.begin(), 0);
    cout << cnt_colony(map, sorted_map_item, map_size) << "\n";
    return 0;
}