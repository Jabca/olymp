def manacher_odd(s):
    s = [-1] + s + [-3]
    n = len(s)
    res = [0] * n
    l = 0
    r = 0
    print(s)
    for i in range(1, n - 1):
        res[i] = max(0, min(r - i, res[l + (r - i)]))
        while s[i - res[i]] == s[i + res[i]]:
            res[i] += 1
        if i + res[i] > r:
            l = i - res[i]
            r = i + res[i]
    return res[1:-1]

def manacher_even(s):
    q = []
    for el in s:
        q.append(-2)
        q.append(el)
    q.append(-2)
    print(q)
    res = manacher_odd(q)[1:-1]
    return [x // 2 for x in res[1::2]]


n, k = map(int, input().split())
a = list(map(int, input().split()))
print(manacher_even(a))