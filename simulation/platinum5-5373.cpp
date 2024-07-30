#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<vector<char> > matrix;

matrix L(3, vector<char>(3,'g'));
matrix B(3, vector<char>(3,'o'));
matrix U(3, vector<char>(3,'w'));
matrix F(3, vector<char>(3,'r'));
matrix R(3, vector<char>(3,'b'));
matrix D(3, vector<char>(3,'y'));
matrix mycube[6]={L,B,U,F,R,D};


/* -만하자. +는 - 3번과 같다.
// 각 동작은 동시에 이루어져야한다. 순차적이면 안됨
// 배열 회전함수는 따로 만들자
(1) 을 (2)로 교체
1. L-
(u,0,c) (f,0,c)
(f,0,c) (d,2,rev.c)
(d,2,c) (b,2,c)
(b,2,c) (u,0,rev.c)

2. B-
(u,0,r) (L,0,rev.c)
(L,0,c) (d,0,rev.r)
(d,0,r) (r,2,c)
(r,2,c) (u,0,r)

3. U-
(L,0,r) (B,0,r)
(B,0,r) (r,0,r)
(r,0,r) (f,0,r)
(f,0,r) (L,0,r)

4. F-
(u,2,r) (r,0,c)
(r,0,c) (d,2,r)
(d,2,r) (L,2,rev.c)
(L,2,c) (u,2,rev.r)

5. R-
(u,2,c) (b,0,rev.c)
(b,0,c) (d,0,c)
(d,0,c) (f,2,rev.c)
(f,2,c) (u,2,c)

6. D-
(r,2,r) (b,2,r)
(b,2,r) (L,2,r)
(L,2,r) (f,2,r)
(f,2,r) (r,2,r)
*/

void rotateMatrix(matrix &mat, bool clockwise) {
    matrix temp = mat;
    if (clockwise) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = temp[2 - j][i];
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = temp[j][2 - i];
            }
        }
    }
}

void rotate(char face, char clock) {
    bool clockwise = (clock == '+');
    if (face == 'L') {
        rotateMatrix(mycube[0], clockwise);
        vector<char> temp(3);
        for (int i = 0; i < 3; i++) temp[i] = mycube[2][i][0];
        if (clockwise) {
            for (int i = 0; i < 3; i++) mycube[2][i][0] = mycube[3][i][0];
            for (int i = 0; i < 3; i++) mycube[3][i][0] = mycube[5][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[5][i][2] = mycube[1][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[1][i][2] = temp[i];
        } else {
            for (int i = 0; i < 3; i++) mycube[2][i][0] = mycube[1][i][2];
            for (int i = 0; i < 3; i++) mycube[1][i][2] = mycube[5][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[5][i][2] = mycube[3][2 - i][0];
            for (int i = 0; i < 3; i++) mycube[3][i][0] = temp[i];
        }
    } else if (face == 'B') {
        rotateMatrix(mycube[1], clockwise);
        vector<char> temp(3);
        for (int i = 0; i < 3; i++) temp[i] = mycube[2][0][2 - i];
        if (clockwise) {
            for (int i = 0; i < 3; i++) mycube[2][0][i] = mycube[0][i][0];
            for (int i = 0; i < 3; i++) mycube[0][i][0] = mycube[5][0][i];
            for (int i = 0; i < 3; i++) mycube[5][0][i] = mycube[4][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[4][i][2] = temp[i];
        } else {
            for (int i = 0; i < 3; i++) mycube[2][0][i] = mycube[4][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[4][i][2] = mycube[5][0][2 - i];
            for (int i = 0; i < 3; i++) mycube[5][0][i] = mycube[0][i][0];
            for (int i = 0; i < 3; i++) mycube[0][i][0] = temp[2 - i];
        }
    } else if (face == 'U') {
        rotateMatrix(mycube[2], clockwise);
        vector<char> temp(3);
        for (int i = 0; i < 3; i++) temp[i] = mycube[0][0][i];
        if (clockwise) {
            for (int i = 0; i < 3; i++) mycube[0][0][i] = mycube[1][0][i];
            for (int i = 0; i < 3; i++) mycube[1][0][i] = mycube[4][0][i];
            for (int i = 0; i < 3; i++) mycube[4][0][i] = mycube[3][0][i];
            for (int i = 0; i < 3; i++) mycube[3][0][i] = temp[i];
        } else {
            for (int i = 0; i < 3; i++) mycube[0][0][i] = mycube[3][0][i];
            for (int i = 0; i < 3; i++) mycube[3][0][i] = mycube[4][0][i];
            for (int i = 0; i < 3; i++) mycube[4][0][i] = mycube[1][0][i];
            for (int i = 0; i < 3; i++) mycube[1][0][i] = temp[i];
        }
    } else if (face == 'F') {
        rotateMatrix(mycube[3], clockwise);
        vector<char> temp(3);
        for (int i = 0; i < 3; i++) temp[i] = mycube[2][2][i];
        if (clockwise) {
            for (int i = 0; i < 3; i++) mycube[2][2][i] = mycube[4][i][0];
            for (int i = 0; i < 3; i++) mycube[4][i][0] = mycube[5][2][2 - i];
            for (int i = 0; i < 3; i++) mycube[5][2][i] = mycube[0][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[0][i][2] = temp[i];
        } else {
            for (int i = 0; i < 3; i++) mycube[2][2][i] = mycube[0][i][2];
            for (int i = 0; i < 3; i++) mycube[0][i][2] = mycube[5][2][2 - i];
            for (int i = 0; i < 3; i++) mycube[5][2][i] = mycube[4][2 - i][0];
            for (int i = 0; i < 3; i++) mycube[4][i][0] = temp[i];
        }
    } else if (face == 'R') {
        rotateMatrix(mycube[4], clockwise);
        vector<char> temp(3);
        for (int i = 0; i < 3; i++) temp[i] = mycube[2][i][2];
        if (clockwise) {
            for (int i = 0; i < 3; i++) mycube[2][i][2] = mycube[1][2 - i][0];
            for (int i = 0; i < 3; i++) mycube[1][i][0] = mycube[5][i][0];
            for (int i = 0; i < 3; i++) mycube[5][i][0] = mycube[3][2 - i][2];
            for (int i = 0; i < 3; i++) mycube[3][i][2] = temp[i];
        } else {
            for (int i = 0; i < 3; i++) mycube[2][i][2] = mycube[3][i][2];
            for (int i = 0; i < 3; i++) mycube[3][i][2] = mycube[5][2 - i][0];
            for (int i = 0; i < 3; i++) mycube[5][i][0] = mycube[1][i][0];
            for (int i = 0; i < 3; i++) mycube[1][i][0] = temp[2 - i];
        }
    } else if (face == 'D') {
        rotateMatrix(mycube[5], clockwise);
        vector<char> temp(3);
        for (int i = 0; i < 3; i++) temp[i] = mycube[3][2][i];
        if (clockwise) {
            for (int i = 0; i < 3; i++) mycube[3][2][i] = mycube[4][2][i];
            for (int i = 0; i < 3; i++) mycube[4][2][i] = mycube[1][2][i];
            for (int i = 0; i < 3; i++) mycube[1][2][i] = mycube[0][2][i];
            for (int i = 0; i < 3; i++) mycube[0][2][i] = temp[i];
        } else {
            for (int i = 0; i < 3; i++) mycube[3][2][i] = mycube[0][2][i];
            for (int i = 0; i < 3; i++) mycube[0][2][i] = mycube[1][2][i];
            for (int i = 0; i < 3; i++) mycube[1][2][i] = mycube[4][2][i];
            for (int i = 0; i < 3; i++) mycube[4][2][i] = temp[i];
        }
    }
}

void printUface() {
    matrix face = mycube[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << face[i][j];
        }
        cout << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            string op;
            cin >> op;
            char face = op[0], clock = op[1];
            rotate(face, clock);
        }
        printUface();
    }
    return 0;
}