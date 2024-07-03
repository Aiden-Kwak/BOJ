#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 0<=N<=500000
// 0<=k<=500000
// x-1(1s), x+1(1x), 2x(1s) : subin
// bro 이동에 가속존재. bro는 +-1 이동만 가능하며 초당 가속1 존재.
// bro는 계속 앞으로. 초별 위치를 전부 큐에 넣고 너비우선탐색 돌려버리기.

// 찾는 위치 500000 이상 경우 예외처리 필요.

// 동생에 초점잡아야한다. 수빈이 14초에 ㅁ 방문, 동생이 20에 ㅁ 방문이라면 둘은 20초에 만난다.
// 수빈이 동생올동안 앞뒤로 움직이고있으면 되니까.
// 시간 초과 방지하려면 동생의 가능한 위치를 미리 벡터에 넣어두자.

int bfs(int subin, int bro){
    queue<int> q;
    vector<int> time(1000001, -1); // 위치별로 시간기록해서, visited용으로도 쓸거임.
    vector<int> bro_pos_hist(500000, -1); // bro_pos_hist[1]에는 1초경과후 bro의 위치 기록
    
    // bro_pos_hist vector generate
    bro_pos_hist[0]=bro;
    int bro_init=bro;
    int btime=0;
    while (bro_init <= 500000) {
        btime++;
        bro_init += btime;
        if (bro_init <= 500000) {
            bro_pos_hist[btime] = bro_init;
        } else {
            break;
        }
    }

    // 예외처리. 시간아끼기
    if(subin==bro) return 0;
    if(bro >= 500000) return -1;

    // subin hist generate
    q.push(subin);
    time[subin]=0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int subin_pos[3] = {node - 1, node + 1, 2 * node};
        int now_time = time[node];
        for (int i = 0; i < 3; i++) {
            int next = subin_pos[i];
            if (next >= 0 && next <= 1000000 && time[next] == -1) {
                time[next] = time[node] + 1;
                q.push(next);
                if (next == bro) {
                    return time[next];
                }
                if (time[next] < bro_pos_hist.size() && bro_pos_hist[time[next]] != -1 && bro_pos_hist[time[next]] == next) { // 수빈의 다음경로가 동생경로상에 존재
                    return time[next];
                }
            }
        }
    }

    return -1;

}
int main(void){
    int subin, bro;
    cin >> subin >> bro;
    int result = bfs(subin, bro);
    cout << result << endl;
}
