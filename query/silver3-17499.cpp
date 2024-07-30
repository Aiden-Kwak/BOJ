#include <iostream>
#include <vector>
using namespace std;

class CircularArray {
private:
    vector<int> data;
    int start;
    int size;

public:
    CircularArray(int n) : data(n), start(0), size(n) {}

    void one(int i, int x) {
        int real_index = (start + i - 1) % size;
        data[real_index] += x;
    }

    void two(int s) {
        start = (start - s + size) % size;
    }

    void three(int s) {
        start = (start + s) % size;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[(start + i) % size] << ' ';
        }
        cout << '\n';
    }

    void initialize(vector<int>& initial_data) {
        data = initial_data;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    CircularArray array(N);
    vector<int> initial_data(N);
    for(int i=0;i<N;i++){
        cin >> initial_data[i];
    }
    array.initialize(initial_data);

    for (int q = 0; q < Q; q++) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            array.one(i, x);
        } else if (op == 2) {
            int s;
            cin >> s;
            array.two(s);
        } else if (op == 3) {
            int s;
            cin >> s;
            array.three(s);
        }
    }

    array.print();
    return 0;
}