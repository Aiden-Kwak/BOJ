#include<iostream>

using namespace std;

int main(void){
    int change;
    cin >> change; //change=13
    //cout << change << "\n";
    int num_coin, num_five, num_two;

    int percent_five=change%5; //perent_five=13%5=3
    //cout << percent_five << "\n";
    if(change==1 || change==3) {
        cout << -1 << "\n";
        return 0;
    }
    if(percent_five%2==0){//3%2!=0
        num_five=change/5;
        num_two=(change-num_five*5)/2;
    }else{
        num_five=change/5 - 1;//num_five=13/5-1=1
        //cout << num_five << "\n";
        num_two=(change-num_five*5)/2;//num_two=(13-5)/2=4
        //cout << num_two << "\n";
    }
    num_coin=num_five+num_two;//1+4=5
    cout << num_coin << "\n";
    return 0;
}