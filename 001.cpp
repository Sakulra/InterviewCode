#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

int maxCharCount(const std::string& s) {
    std::unordered_map<char, int> countMap;
    
    // 遍历字符串，统计每个字符（不区分大小写）的出现次数
    for (char ch : s) {
        char lowerCh = std::tolower(static_cast<unsigned char>(ch));
        countMap[lowerCh]++;
    }
    
    int maxCount = 0;
    for (const auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    }
    
    return maxCount;
}

int main() {
    // 示例测试
    std::cout << maxCharCount("abcde") << std::endl;    // 输出: 1
    std::cout << maxCharCount("aabbcde") << std::endl;  // 输出: 2
    
    return 0;
}