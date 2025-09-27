#include <iostream>
#include <string>
using namespace std;

bool isApproxEqual(char a, char b) {
    return a == b || abs(a - b) == 1;
}

int minOperationsToEliminateApproximateNeighbors(string& word) {
    int count = 0;
    for (int i = 1; i < (int)word.size(); i++) {
        if (isApproxEqual(word[i], word[i - 1])) {
            count++;
            // 修改当前 word[i]，避免与前一个继续冲突
            // 用一个不影响后续比较的特殊符号代替（这里用 '*'）
            word[i] = '*';
        }
    }
    return count;
}

int main() {
    string word;
    cin >> word;
    int result = minOperationsToEliminateApproximateNeighbors(word);
    cout << result << endl;
    return 0;
}