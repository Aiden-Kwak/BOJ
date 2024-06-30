#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long

int main(void) {
    ll grandpa, num_channel, init_channel;
    cin >> grandpa >> num_channel >> init_channel;

    unordered_map<ll, ll> hated_to_favorite; // hated 채널을 key, favorite 채널을 value로 저장
    ll like, hate;
    
    for (int i = 0; i < grandpa; i++) { 
        cin >> like >> hate;
        hated_to_favorite[hate] = like;
    }

    vector<ll> visited(num_channel + 1, 0); 
    ll cnt = 0;

    while (true) {
        if (visited[init_channel] == 1) {
            printf("%d\n", -1);
            return 0;
        }

        visited[init_channel] = 1;

        if (hated_to_favorite.find(init_channel) != hated_to_favorite.end()) {
            init_channel = hated_to_favorite[init_channel];
            cnt++;
        } else {
            printf("%lld\n", cnt);
            return 0;
        }
    }
}
