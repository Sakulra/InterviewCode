
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// 判断两个字符是否近似相等，注意是bool而不是def
bool isApproxEqual(char a, char b) {
    return a == b || abs(a - b) == 1;
}

int minOperationsToEliminateApproximateNeighbors(string& word) {
    // 函数内部需要修改传入的参数，选择string &
    // 函数内部不需要修改传入的参数，选择const string &
    // copy一份数据到函数内部，选择string
    int count = 0;

    for (int i = 1; i < (int)word.size(); i++) {

        if (isApproxEqual(word[i], word[i - 1])) {
            count++;

            // 寻找一个与前后字符都不近似相等的小写字母
            // 卡住我的点
            for (char c = 'a'; c <= 'z'; c++) {

                // 不能与前一个字符近似相等
                if (isApproxEqual(c, word[i - 1])) {
                    continue;
                }

                // 不能与后一个字符近似相等
                if (i < (int)word.size() - 1 &&isApproxEqual(c, word[i + 1])) {
                    continue;
                }

                // 找到符合条件的字符，进行修改
                word[i] = c;
                break;
            }
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
// 我的源程序，考虑不周
// bool similarequal(char a, char b){
//     return a == b || abs(a-b) == 1;
// }

// int erase(string& s){
//     int count = 0;
//     // 循环节边界错误
//     // 遗漏了最后一个字符。比如 "ba" 这种两个字符的字符串，循环 1 < 1 一次都不进，会直接返回 0，
//     // 但 'a' 和 'b' 是近似相等的，本应处理
//     // s.length() - 1 在 s.size() == 0 时会下溢成 SIZE_MAX，若真传空串，循环条件会为真，
//     // 随后 s[i] 越界访问 → UB
//     for (int i = 1; i < s.length()-1; i++){
//         if (similarequal(s[i],s[i-1])){
//             count++;
//             for (char c = 'a'; c <= 'z'; c++){
//                 if (similarequal(c, s[i-1])){
//                     continue;
//                 }
//                 // i < s.size()-1 在在 s.size() 很小时会因为无符号下溢变成 i < SIZE_MAX
//                 // 可加 (int) 就消除了这个隐患
//                 if (i < s.size()-1&&similarequal(c, s[i+1])){
//                     continue;
//                 }
//                 s[i] = c;
//                 break;
//             }
//         }
//     }
//     return count;
// }
// int main(){
//     string s = "aaaaa";
//     // 不能直接往erase()传入“aaaaa”，会因为传入类型和函数定义接收类型不一致报错
//     int a = erase(s);
//     cout << a << endl;
//     return 0;