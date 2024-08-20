#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n_room; cin >> n_room;
    vector<int> room(n_room+1); // no zero index
    for(int i=1;i<=n_room;i++){
        cin >> room[i];
    }
    int m_inst_capa, s_inst_capa;
    cin >> m_inst_capa >> s_inst_capa;
    
    ll TOTAL_INST_NUM=0; 
    for(int i=1;i<=n_room;i++){
        int S_INST_RESPONSE=room[i]-m_inst_capa;
        if(S_INST_RESPONSE<=0){
            TOTAL_INST_NUM+=1; continue;
        }
        int S_INST_NEED=(int)ceil(float(S_INST_RESPONSE)/s_inst_capa);
        TOTAL_INST_NUM+=(S_INST_NEED+1);
    }
    printf("%lld\n", TOTAL_INST_NUM);
    return 0;
}