import sys
import collections
input = sys.stdin.readline

def prime_list(n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    sieve = [True] * n
    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if sieve[i] == True:           # i가 소수인 경우
            for j in range(i+i, n, i): # i이후 i의 배수들을 False 판정
                sieve[j] = False
    return [i for i in range(2, n) if i>999 and sieve[i] == True]

thousand_overlist = prime_list(9999)
for _ in range(int(input())):
    start, dest = map(int, input().split())
    visit = [0 for _ in range(10000)]
    q = collections.deque([[start, 0]])
    flag=0
    while q:
        cur, cost = q.popleft()
        if cur==dest:
            print(cost)
            flag=1
            break
        
        sub_cur = str(cur)
        able_list = []
        for num in thousand_overlist:
            sub_num = str(num)
            for idx in range(4):
                if sub_num[:idx]==sub_cur[:idx] and sub_num[idx+1:]==sub_cur[idx+1:] and not visit[num]:
                    q.append([num, cost+1])
                    visit[num]=1
    if not flag:
        print('impossible')
