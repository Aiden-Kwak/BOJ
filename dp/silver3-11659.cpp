#include<iostream>
#include<vector>
using namespace std;

void testPrintList(const vector<int> &l){
    for(int i=0;i<l.size();i++){
        cout << l[i] << ' ';
    }cout << endl;
}
int main(void){
    int n,m;
    cin >> n >> m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> num(n+1);
    for(int i=1;i<=n;i++){
        cin >> num[i];
    }
    vector<int> sum(n+1);
    int ssum=0;
    for(int i=1;i<=n;i++){
        ssum+=num[i];
        //cout << ssum << ',' << num[i] << endl;
        sum[i]=ssum;
    }
    //testPrintList(sum);
    for(int i=0;i<m;i++){
        int a,b; //[a,b]
        cin >> a >> b;
        //[2,4]=sum[4]-sum[1]
        cout << sum[b]-sum[a-1] << '\n';
    }
    return 0;
}