#include<vector>
#include<string>
#include<iostream>
using namespace std;

/*
어떤 숫자인지 어떻게 판별할 것인가?
row 개수는 5개 고정. 

0 0 0 [-] [0] [-]
0 0 0 [1] [2] [3]
0 0 0 [-] [4] [-]

 -  [0]  -> 양끝 [10] [11] 추가
| | [1] [2]
 - [3]   -> 양끝 [8] [9] 추가
| | [4] [5]
 _ [6]   -> 양끝 [12] [13] 추가
*/
//4: 10 11 1 2 8 9 3 5 6 : 0 1 1 1 0 1 1 0 1 1 1 1 0 0
int number[10][13]={
    {1,1,1,0,1,1,1,1,1,1,1,1,1},//0: 012456
    {1,0,0,1,0,0,1,0,0,0,0,0,0},//1: 036 -> 1구분이 안가: 
    {1,0,1,1,1,0,1,1,1,1,1,1,1},//2:02346
    {1,0,1,1,0,1,1,1,1,1,1,1,1},//3:02356
    {0,1,1,1,0,1,0,1,1,1,1,0,1},//4:12356
    {1,1,0,1,0,1,1,1,1,1,1,1,1},//5:01356
    {1,1,0,1,1,1,1,1,1,1,1,1,1},//6:013456
    {1,0,1,0,0,1,0,0,1,1,1,0,1},//7:025
    {1,1,1,1,1,1,1,1,1,1,1,1,1},//8:0123456
    {1,1,1,1,0,1,1,1,1,1,1,1,1}//9:012356
}; // 실수로 7번째 디짓이 빼먹음. 7번째를 8이라고 생각하면 됨. 

vector<string> croped_map(vector<string>& map, int start){
    vector<string> output(5);
    for(int i=0;i<5;i++){
        output[i]=map[i].substr(start,3);
    }
    return output;
}

int is_number(vector<string>& croped_map){
    //test
    /*
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            cout << croped_map[i][j];
        }
        cout << endl;
    }cout<<endl;*/
    //endtest

    int inspect[13]={0};
    if(croped_map[0][1]=='#'){//0
            inspect[0]=1;
    }
    if(croped_map[1][0]=='#'){//1
            inspect[1]=1;
    }
    if(croped_map[1][2]=='#'){//2
            inspect[2]=1;
    }
    if(croped_map[2][1]=='#'){//3
            inspect[3]=1;
    }
    if(croped_map[3][0]=='#'){//4
            inspect[4]=1;
    }
    if(croped_map[3][2]=='#'){//5
            inspect[5]=1;
    }
    if(croped_map[4][1]=='#'){//6
            inspect[6]=1;
    }
    if(croped_map[2][0]=='#'){//7
            inspect[7]=1;
    }
    if(croped_map[2][2]=='#'){//8
            inspect[8]=1;
    }
    if(croped_map[0][0]=='#'){//9
            inspect[9]=1;
    }
    if(croped_map[0][2]=='#'){//10
            inspect[10]=1;
    }
    if(croped_map[4][0]=='#'){//11
            inspect[11]=1;
    }
    if(croped_map[4][2]=='#'){//12
            inspect[12]=1;
    }
    /*
    for(int i=0;i<15;i++){//그냥 14번 반복용
        if(croped_map[0][1]=='#'){//0
            inspect[0]=1;
        }else if(croped_map[0][1]=='.'){//0
            inspect[0]=0;
        }else if(croped_map[1][0]=='#'){//1
            inspect[1]=1;
        }else if(croped_map[1][0]=='.'){//1
            inspect[1]=0;
        }else if(croped_map[1][2]=='#'){//2
            inspect[2]=1;
        }else if(croped_map[1][2]=='.'){//2
            inspect[2]=0;
        }else if(croped_map[2][1]=='#'){//3
            inspect[3]=1;
        }else if(croped_map[2][1]=='.'){//3
            inspect[3]=0;
        }else if(croped_map[3][0]=='#'){//4
            inspect[4]=1;
        }else if(croped_map[3][0]=='.'){//4
            inspect[4]=0;
        }else if(croped_map[3][2]=='#'){//5
            inspect[5]=1;
        }else if(croped_map[3][2]=='.'){//5
            inspect[5]=0;
        }else if(croped_map[4][1]=='#'){//6
            inspect[6]=1;
        }else if(croped_map[4][1]=='.'){//6
            inspect[6]=0;
        }
    }*/
    /* test*/
    /*
    for(int i=0;i<7;i++){
        cout << inspect[i]<<' ';
    }
    cout<< endl;*/

    // number 검사
    int flag=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<13;j++){
            if(number[i][j]==inspect[j]){
                flag++;
            }
            if(flag==13) return i;
        }
        //cout << "flag: "<< flag << endl;
        flag=0;
    }
    return -1;
}

int main(void){
    int n;
    cin >> n;
    string signal;
    cin >> signal;
    // ###..#..
    // #.#..#..
    // ###..#..
    // ...
    /*
    주어진 배열 맨끝에 한줄 추가 : 맨끝 1 대비
    3칸씩 떼어서 검사. > 숫자임이 확인되면 바로 다음 3칸 다시 검사. (0에서 확인 성공시 시작점 3으로) -> 폐기. 맨앞1경우 예외발생.
    숫자가 아닐경우 옆으로 한칸 이동해서 다시 3칸씩 떼어서 검사. (0에서 확인 실패시 시작점 1로)
    >>
    그냥 계속 1씩 넘겨야해.
    */
    vector<string> map(5);
    for(int i=0;i<5;i++){
        string temp=signal.substr(i*(n/5), n/5); // 0: 0,7// 1: 8,15..
        map[i]="."+temp+"!"; // 시작, 맨끝에 한줓추가: 시작점에도 1로 시작할수 있어.
        //cout << "check: "<<map[i] << endl;
    }
    /*
    너비가 8이라면, 양끝에 2붙이고, 8번 검사함.> 너비만큼 검사함.
    */
    for(int i=0;i<n/5;i++){
        vector<string> cmap=croped_map(map, i);
        int whatisnumber=is_number(cmap);
        if(whatisnumber!=-1){//어떤 숫자인지 뱉거나 -1을 뱉는다.
            cout<<whatisnumber;
        }
    }
    cout<<endl;
    return 0;   
}