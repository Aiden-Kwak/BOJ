#include<iostream>
#include<vector>
#include<string>
using namespace std;

string opcodev[12]={"ADD", "SUB", "MOV", "AND",
"OR", "NOT", "MULT", "LSFTL", "LSFTR", "ASFTR"
,"RL", "RR"};

string decimalToBinary(int decimal, int n){
    char binary[n+1];
    //string binary(n, '0');
    for(int i=n-1;i>=0;i--){
        int temp = (decimal >> i) & 1;
        binary[n-1-i]=temp+'0';
    }
    // 주의: 스트링은 어차피 뒤에 널붙여줘
    //binary[n]='\0'; 
    return string(binary);
}
// 주의: C++에서 ''는 단일문자리터럴에만 씀. ""써야해.
// opcode
int main(void){
    int n;
    cin >> n;
    vector<string> output(n);
    for(int i=0;i<n;i++){
        string opcode;
        int one, two, three;
        cin >> opcode >> one >> two >> three;
        string opcodeb, ff ,rD, rA, C, temp;
        // opcode 마지막이 C인지 확인, 맞으면 temp에 C제거한거넣기, 아니면 그대로 temp에
        // 마지막이 C였으면 ff에 10, 아니면 00
        if(opcode[opcode.length()-1]=='C'){
            opcode.pop_back();
            temp=opcode;
            ff="10";
        }else{
            temp=opcode;
            ff="00";
        }
        // for로 opcode순회해서 temp와 같으면 i값을 바이너리로 변환(n=4).
        // 변환값을 opcodeb에 저장.
        for(int i=0;i<12;i++){
            if(opcodev[i]==temp){
                opcodeb=decimalToBinary(i,4);
                break;
            }
        }
        // one을 바이너리로 변환후 rD에(n=3)
        rD=decimalToBinary(one, 3);
        //cout << "rD:" << rD;
        // opcodeb가 0101 or 0010이면 rA=000
        if(opcodeb=="0101" || opcodeb=="0010"){
            rA="000";
        }
        // 아니면 two 를 바이너리 변환 후 rA에 저장(n=3)
        else{
            rA=decimalToBinary(two, 3);
        }
        // 만약 ff가 00이면 three 바이너리(n=3)+'0'을 C에 저장
        if(ff=="00"){
            C=decimalToBinary(three,3)+'0';
        }
        // 아니면 three를 바이너리(n=4)로 변환 후 C에 저장
        else{
            C=decimalToBinary(three,4);
        }
        output[i]=opcodeb+ff+rD+rA+C;
        //cout << endl;
        //cout << opcodeb<< ff << rD << rA << C << endl;
    }
    for(int i=0;i<n;i++){
        cout << output[i] << endl;
    }
    return 0;
}