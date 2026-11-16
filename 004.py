def minOperationsToEliminateApproximateNeighbors(word: str) -> int:

    def is_approx_equal(a: str, b: str) -> bool:
        #ord()内置函数，用于将单个字符转换为其对应的 ASCII 或 Unicode 数值
        return a == b or abs(ord(a) - ord(b)) == 1

    word = list(word)
    count = 0

    for i in range(1, len(word)):
        if is_approx_equal(word[i], word[i - 1]):
            count += 1

            # 寻找一个与前后字符都不近似相等的小写字母
            for c in "abcdefghijklmnopqrstuvwxyz":
                if not is_approx_equal(c, word[i - 1]):
                    if i == len(word) - 1 or not is_approx_equal(c, word[i + 1]):
                        word[i] = c
                        break

    return count


# 测试
if __name__ == "__main__":
    print(minOperationsToEliminateApproximateNeighbors("aaaaa"))  # 2
    print(minOperationsToEliminateApproximateNeighbors("abc"))    # 1
    print(minOperationsToEliminateApproximateNeighbors("zaz"))    # 0