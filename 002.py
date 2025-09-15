import math

def is_perfect_number(num):
    """
    判断一个正整数是否为完美数
    
    参数:
    num: 正整数
    
    返回:
    bool: 如果是完美数返回True，否则返回False
    """
    if num <= 1:
        return False  # 完美数必须大于1
    
    # 初始化因子和为1（因为1是所有数的因子）
    sum_of_divisors = 1
    sqrt_num = int(math.isqrt(num))  # 使用整数平方根
    
    # 遍历可能的因子
    for i in range(2, sqrt_num + 1):
        if num % i == 0:
            sum_of_divisors += i
            complement = num // i
            if complement != i:  # 避免重复添加平方根
                sum_of_divisors += complement
    
    return sum_of_divisors == num


# 测试函数
def test_perfect_numbers():
    """测试一些已知的完美数"""
    test_cases = [
        (6, True),      # 第一个完美数
        (28, True),     # 第二个完美数
        (496, True),    # 第三个完美数
        (8128, True),   # 第四个完美数
        (8, False),     # 不是完美数
        (12, False),    # 不是完美数
        (1, False),     # 边界情况
        (2, False),     # 不是完美数
    ]
    
    print("测试结果:")
    for num, expected in test_cases:
        result = is_perfect_number(num)
        status = "✓" if result == expected else "✗"
        print(f"{status} {num}: {result} (期望: {expected})")


# 示例使用
if __name__ == "__main__":
    # 测试已知的完美数
    test_perfect_numbers()
    
    print("\n" + "="*40)
    
    # 用户输入测试
    try:
        user_input = int(input("请输入一个正整数: "))
        if user_input <= 0:
            print("请输入正整数！")
        else:
            if is_perfect_number(user_input):
                print(f"{user_input} 是完美数！")
            else:
                print(f"{user_input} 不是完美数")
    except ValueError:
        print("请输入有效的整数！")