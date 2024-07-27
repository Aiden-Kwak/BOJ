#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef vector<vector<vector<int> > > cube;
typedef pair<pair<int,int>, int> mytuple;
// (1): mytuple.first.first
// (2): mytuple.first.second
// (3): mytuple.second

int m,n,h;

void testPrintMap(cube &map){
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cout << map[i][j][k] << ' ';
            }
            cout << endl;
        }
    }
}

bool isValidArea(int z, int y, int x){
    if(x>=0 && x<m && y>=0 && y<n && z>=0 && z<h){
        return true;
    }else return false;
}

int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};

queue<mytuple> q;
int day=0;
void bfs(cube &tomato){
    //q.push(make_pair(make_pair(x,y),z));
    while(!q.empty()){
        int qsize=q.size();
        for(int i=0;i<qsize;i++){
            mytuple node=q.front();
            q.pop();
            int z=node.first.first;
            int y=node.first.second;
            int x=node.second;
            for(int j=0;j<6;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                int nz=z+dz[j];
                if(isValidArea(nz,ny,nx) && tomato[nz][ny][nx]==0){
                    tomato[nz][ny][nx]=1;
                    mytuple next=make_pair(make_pair(nz,ny),nx);
                    q.push(next);
                }
            }
        }
        if(!q.empty()) day++;
    }
}

bool finalPass(cube &tomato){//아직도 안익은게 있는가!
    int check=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tomato[i][j][k]==0){
                    check++;
                }
            }
        }
    }
    if(check==0) return true;
    else return false;
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    cube tomato(h, vector<vector<int> >(n, vector<int>(m)));
    
    int num_green_tomato=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> tomato[i][j][k];
                int temp_tomato=tomato[i][j][k];
                if(temp_tomato==1){
                    q.push(make_pair(make_pair(i,j),k));
                }
                if(temp_tomato==0) num_green_tomato++;
            }
        }
    }
    //testPrintMap(tomato);
    if(num_green_tomato==0){//이미 안익은 토마토가 없어.
        cout << "0" << endl;
        return 0;
    }
    bfs(tomato);
    //testPrintMap(tomato);
    if(!finalPass(tomato)){//아직안익었어
        cout << "-1" << endl;
        return 0;
    }else{//다익음. 날짜내놔
        cout << day << endl;
        return 0;
    }
}