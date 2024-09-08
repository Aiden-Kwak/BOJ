#include<iostream>
#include<vector>
using namespace std;

void calc_subseq(vector<int> &number, vector<vector<int> > &seq){
    
    for(int i=0;i<(1<<number.size());i++){
        vector<int> temp;
        for(int j=0;j<number.size();j++){
            if(i&(1<<j)){
                temp.push_back(number[j]);
            }
        }seq.push_back(temp);
    }
}
void printArray(vector<vector<int> >&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout << arr[i][j] << ' ';
        }cout << endl;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,ss;cin >> n >> ss;
    vector<int> number(n);
    for(int i=0;i<n;i++){
        cin >> number[i];
    }
    vector<vector<int> > subseq;
    calc_subseq(number, subseq);
    printArray(subseq);

}