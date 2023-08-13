from sys import stdin

for _ in range(3) :
    n = int(stdin.readline())
    ans = 0
    for _ in range(n) :
        ans += int(stdin.readline())
    if (ans == 0) :
        print(0)
    elif (ans < 0) :
        print('-')
    else :
        print('+')