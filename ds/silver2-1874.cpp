#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    stack<int> st;
    vector<string> operations;
    int current = 1;
    
    for (int i = 0; i < n; i++) {
        int num = numbers[i];
        
        while (current <= num) {
            st.push(current);
            operations.push_back("+");
            current++;
        }
        
        if (!st.empty() && st.top() == num) {
            st.pop();
            operations.push_back("-");
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    // 결과 출력 최적화
    for (const string& op : operations) {
        cout << op << "\n";
    }

    return 0;
}
