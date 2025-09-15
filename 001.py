def sol(text :str) -> int:
    text = text.lower()
    freq = {}
    for ch in text:
        #isalnum如果是字母或数字则返回真
        if ch.isalnum():
            #get(key,default)返回key得值，如果值不在字典中就返回default值。
            freq[ch] = freq.get(ch, 0) + 1
    print(freq)
    return max(freq.values()) if freq else 0

print(sol("abcde"))