#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;

int n;
int ans = 0;

int getMax(const vector<vector<int> >& board) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, board[i][j]);
        }
    }
    return res;
}

// 오른쪽 이동
vector<vector<int> > right(vector<vector<int> > board) {
    vector<vector<bool> > check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (board[i][j] == 0)
                continue;
            for (int k = j + 1; k < n; k++) {
                if (board[i][k] == board[i][k - 1] && !check[i][k]) {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                } else if (board[i][k] == 0) {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                } else {
                    break;
                }
            }
        }
    }
    return board;
}

// 왼쪽 이동
vector<vector<int> > left(vector<vector<int> > board) {
    vector<vector<bool> > check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (board[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--) {
                if (board[i][k] == board[i][k + 1] && !check[i][k]) {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    check[i][k] = true;
                    break;
                } else if (board[i][k] == 0) {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                } else {
                    break;
                }
            }
        }
    }
    return board;
}

// 아래 이동
vector<vector<int> > down(vector<vector<int> > board) {
    vector<vector<bool> > check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (board[j][i] == 0)
                continue;
            for (int k = j + 1; k < n; k++) {
                if (board[k][i] == board[k - 1][i] && !check[k][i]) {
                    board[k][i] *= 2;
                    board[k - 1][i] = 0;
                    check[k][i] = true;
                    break;
                } else if (board[k][i] == 0) {
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = 0;
                } else {
                    break;
                }
            }
        }
    }
    return board;
}

// 위로 이동
vector<vector<int> > up(vector<vector<int> > board) {
    vector<vector<bool> > check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (board[j][i] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--) {
                if (board[k][i] == board[k + 1][i] && !check[k][i]) {
                    board[k][i] *= 2;
                    board[k + 1][i] = 0;
                    check[k][i] = true;
                    break;
                } else if (board[k][i] == 0) {
                    board[k][i] = board[k + 1][i];
                    board[k + 1][i] = 0;
                } else {
                    break;
                }
            }
        }
    }
    return board;
}

void move2048(int L, vector<vector<int> > board) {
    ans = max(ans, getMax(board));
    if (L == 5)
        return;
    move2048(L + 1, right(board));
    move2048(L + 1, left(board));
    move2048(L + 1, up(board));
    move2048(L + 1, down(board));
}

int main() {
    cin >> n;
    vector<vector<int> > board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    move2048(0, board);
    cout << ans << '\n';

    return 0;
}
