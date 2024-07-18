/*
 -   [0]
| |  [1] [2]
 -   [6]
| |  [3] [4]
 _   [5]
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcd[10][7]={
    {1,1,1,1,1,1,0}, // 0 : 012345
    {0,0,1,0,1,0,0}, // 1: 24
    {1,0,1,1,0,1,1}, // 2: 02356
    {1,0,1,0,1,1,1},// 3:02645
    {0,1,1,0,1,0,1},//4:1264
    {1,1,0,0,1,1,1},//5:01645
    {1,1,0,1,1,1,1},//6:016345
    {1,0,1,0,1,0,0},//7:024
    {1,1,1,1,1,1,1},//8:0123456
    {1,1,1,0,1,1,1}//9:012456
};
/*
0,5,6 : "-"
1,2,3,4 : "|"
결국 한줄씩먹여야됨. 
n string을 길이만큼 순회하면서 현재 줄 체크,
line: 0-> digit0, 1+s-> digit6, 2+2s-> digit5, - 해당
나머지이면서 1+s보다 작으면 digit->1,2체크, 1+s보다 크면 digit->3,4 체크
n=0123 가정.
0번째줄, 01234각각에 digit0체크, 매체크후 캐릭터를 s만큼 그리고 ' ', 
lcd[0][0], lcd[1][0], lcd[2][0] 가 각각 1이면 '-', 0이면 ' '*s,
1번째줄, -> 나머지면서 1+s보다 작으므로 digit 1,2체크
lcd[0][1], ' '*s, lcd[0][2], ' ', 
*/

int main(void){
    int s;
    cin >> s;
    string n;
    cin >> n;
    for(int line=0;line<2*s+3;line++){
        for(int x=0;x<n.length();x++){
            int string_digit=int(n[x])-'0';
            //cout<<"digit: "<<string_digit;
            if(line==0){//digit0
                //cout<<lcd[string_digit][0];
                if(lcd[string_digit][0]==1){
                    cout<<" ";
                    for(int i=0;i<s;i++)cout<<"-";
                    cout<<" ";
                    cout<< " ";
                }else{
                    cout<<" ";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout<<" ";
                    cout << " ";
                }
            }else if(line==1+s){//digit6
                if(lcd[string_digit][6]==1){
                    cout<<" ";
                    for(int i=0;i<s;i++)cout<<"-";
                    cout<<" ";
                    cout << " ";
                }else{
                    cout<<" ";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout<<" ";
                    cout << " ";
                }
            }else if(line==2+2*s){//digit5
                if(lcd[string_digit][5]==1){
                    cout<<" ";
                    for(int i=0;i<s;i++)cout<<"-";
                    cout<<" ";
                    cout << " ";
                }else{
                    cout<<" ";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout<<" ";
                    cout << " ";
                }
            }else if(line<1+s){//line!=0 && line!=1+s && line!=2+2*s //digit:1,2
                if(lcd[string_digit][1]==1 && lcd[string_digit][2]==1){
                    cout << "|";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout << "|";
                    cout << " ";
                }else if(lcd[string_digit][1]==1 && lcd[string_digit][2]==0){
                    cout << "|";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout << " ";
                    cout << " ";
                }else if(lcd[string_digit][1]==0 && lcd[string_digit][2]==1){
                    cout << " ";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout << "|";
                    cout << " ";
                }else{
                    for(int i=0;i<s+2;i++)cout<<" ";
                    cout << " ";
                }

            }else{ //digit:3,4
                if(lcd[string_digit][3]==1 && lcd[string_digit][4]==1){
                    cout << "|";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout << "|";
                    cout << " ";
                }else if(lcd[string_digit][3]==1 && lcd[string_digit][4]==0){
                    cout << "|";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout << " ";
                    cout << " ";
                }else if(lcd[string_digit][3]==0 && lcd[string_digit][4]==1){
                    cout << " ";
                    for(int i=0;i<s;i++)cout<<" ";
                    cout << "|";
                    cout << " ";
                }else{
                    for(int i=0;i<s+2;i++)cout<<" ";
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}