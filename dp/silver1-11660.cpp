#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > matrix;

int n;

void testPrintCell(const matrix &cell){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << cell[i][j] << ' ';
        }cout << endl;
    }cout << endl;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> n >> num;
    matrix cell(n+1, vector<int>(n+1)); // 0 안쓸거야
    matrix sum(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++){ // cell
        for(int j=1;j<=n;j++){
            cin >> cell[i][j];
        }
    }

    for(int i=1;i<=n;i++){ // sum
        for(int j=1;j<=n;j++){
            if(i==1 && j==1){
                sum[i][j]=cell[i][j];
            }else if(i==1 && j!=1){
                sum[i][j]=cell[i][j]+sum[i][j-1];
            }else if(i!=1 && j==1){
                sum[i][j]=cell[i][j]+sum[i-1][j];
            }else{
                sum[i][j]=cell[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
    }

    //cout << endl;
    //testPrintCell(cell);
    //testPrintCell(sum);

    for(int i=0;i<num;i++){
        int ans;
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1==1 && y1==1) ans=sum[x2][y2];
        else if(x1!=1 && y1==1){
            ans=sum[x2][y2]-sum[x1-1][y2];
        }else{
            //cout << "\ncheck: " << sum[x2][x2] << sum[x1-1][x2] << sum[x2][y1-1] << sum[x1-1][y1-1] << endl;
            ans=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
        }
        cout << ans << '\n';
    }
    return 0;
}