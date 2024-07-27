#include<iostream>
#include<vector>
using namespace std;

int bongji(int n){ // n=4
    int five=n/5; // five=0
    int five_remain=n-five*5; // remain=2
    if(five_remain%3!=0){ // 2
        while(five>=0){
            five-=1;
            if(five==-1) return -1;
            five_remain=n-five*5;
            if(five_remain%3==0){
                int three=five_remain/3;
                return five+three;
            }
        }
    }else{
        int three=five_remain/3;
        return five+three;
    }
    return -1;
}

int main(void){
    int n;
    cin >> n;
    cout << bongji(n) << endl;
    return 0;
}