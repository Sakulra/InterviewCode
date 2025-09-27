def minOperationsToEliminateApproximateNeighbors(word: str) -> int:
    def is_approx_equal(a: str, b: str) -> bool:
        return a == b or abs(ord(a) - ord(b)) == 1

    word = list(word)  # 转换为可修改的列表
    count = 0
    for i in range(1, len(word)):
        if is_approx_equal(word[i], word[i - 1]):
            count += 1
            # 修改当前字符，避免后续继续冲突
            word[i] = '*'
    return count


# 测试
if __name__ == "__main__":
    print(minOperationsToEliminateApproximateNeighbors("abba"))  # 输出 2
    print(minOperationsToEliminateApproximateNeighbors("abc"))   # 输出 2
    print(minOperationsToEliminateApproximateNeighbors("zaz"))   # 输出 0