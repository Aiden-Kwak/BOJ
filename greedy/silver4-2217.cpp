#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// N개의 로프. 굵기와 길이 다르고 들수있는 중량다르다
// 로프 병렬연결 가능
// 들수있는 최대중량구하기.
int max_weight(int n, vector<int>& w){
    // 제일 작은거, 제일큰거 찾기
    sort(w.begin(), w.end());
    vector<int> total_weight;
    for(int i=0;i<n;i++){
        total_weight.push_back((n-i)*w[i]);
    }
    sort(total_weight.begin(), total_weight.end());
    return total_weight.back();
}

int main(void){
    int num_rope;
    scanf("%d", &num_rope);

    vector<int> weight(num_rope);
    for(int i=0;i<num_rope;i++){
        scanf("%d", &weight[i]);
    }
    printf("%d\n", max_weight(num_rope, weight));
    return 0;
}