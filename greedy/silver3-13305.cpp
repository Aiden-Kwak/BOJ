#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int

using namespace std;
// 우선 소팅 필요할듯.
// 비싼 곳에서는 거리이동에 필요한 최소만 주유
// 가장 싼 곳에선 남은거리 최대 주유.
// 가장 싼곳이 나오기 전까지는 계속 최소만 주유시켜
lli calc_price(int n, 
            const vector<lli>& road, 
            const vector<lli>& city_p){
    
    vector<lli> copy_city_price = city_p;// 5 2 4 1
    copy_city_price.pop_back();//마지막 도시는 필요없음. // 5 2 4
    
    sort(copy_city_price.begin(), copy_city_price.end());
    lli cheap_city=copy_city_price[0];
    lli output=0;
    for(int i=0;i<n-1;i++){
        if(city_p[i]==cheap_city){
            lli cnt_road=0;
            for(int j=i;j<n-1;j++){
                cnt_road+=road[j];
            }
            output+=cnt_road*city_p[i];
            return output;
        }else{
            output+=road[i]*city_p[i];
        }
    }
    return output;
}

int main(void){
    int num_city;
    scanf("%d", &num_city);
    vector<lli> road_price(num_city-1);
    vector<lli> city_price(num_city);
    for(int i=0;i<num_city-1;i++){
        scanf("%lld", &road_price[i]);
    }
    for(int i=0;i<num_city;i++){
        scanf("%lld", &city_price[i]);
    }

    printf("%lld\n", calc_price(num_city, road_price, city_price));
    return 0;
}