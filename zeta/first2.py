def find_lexicographically_smaller_subsequence(s, k, x):
    result = []

    for char in s:
        if char == 'a':
            # If 'a' is needed in the subsequence and it won't exceed the length K
            if k - len(result) > x:
                result.append('a')
        else:  # char == 'b'
            # If 'b' is needed in the subsequence and it won't exceed the allowed count X
            if x > 0:
                result.append('b')
                x -= 1

    return ''.join(result)

# Example usage:
s = 'abab'
k = 3
x = 2
ans = find_lexicographically_smaller_subsequence(s, k, x)
print(ans)
