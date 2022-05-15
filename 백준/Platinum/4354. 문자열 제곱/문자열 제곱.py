import sys
 
while True:
    s = sys.stdin.readline().strip()
    n = len(s)
    if s.startswith('.'):
        exit(0)
 
    pi = [ 0 for i in range(n) ]
    begin = 1
    matched = 0
    answer = 1
    while begin + matched < n:
        if (s[begin + matched] == s[matched]):
            matched += 1
            pi[begin + matched - 1] = matched
            if begin + matched == n and n % (n - matched) == 0:
                answer = max(answer, n // (n - matched))
        else:
            if (matched == 0):
                begin += 1
            else:
                begin += matched - pi[matched - 1]
                matched = pi[matched - 1]
 
    print(answer)