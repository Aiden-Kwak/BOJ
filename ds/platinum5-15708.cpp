#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> hit_list(n);
    for (int i = 0; i < n; ++i) {
        cin >> hit_list[i];
    }

    priority_queue<int> pq;
    int max_stone = 0;
    int current_time = 0;
    int sum = 0;  // 곡괭이질 총시간
    int c = 0;    // 채취바위개수

    for (int i = 0; i < n; ++i) {
        sum += hit_list[i];
        c++;
        pq.push(hit_list[i]);

        while (sum + p * c > t && !pq.empty()) {
            sum -= pq.top();
            pq.pop();
            c--;
        }

        max_stone = max(max_stone, c);

        if (i < n - 1) {
            current_time += p;
            if (current_time > t) break;
        }
    }
    cout << max_stone << endl;
    return 0;
}
