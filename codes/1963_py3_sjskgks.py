import sys
import collections
input = sys.stdin.readline

def prime_list(n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    sieve = [True] * n
    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    for i in range(2, n + 1):
        if i*i>n:
            break
        if sieve[i] == True:           # i가 소수인 경우
            for j in range(i*i, n, i): # i이후 i의 배수들을 False 판정
                sieve[j] = False
    return [i for i in range(2, n) if i>999 and sieve[i] == True]

thousand_overset = set(prime_list(9999))
for _ in range(int(input())):
    start, dest = map(int, input().split())
    visit = [0 for _ in range(10000)]
    q = collections.deque([[start, 0]])
    isReached=False
    while q:
        cur, cost = q.popleft()
        if cur==dest:
            print(cost)
            isReached=True
            break
        division=10
        for _ in range(4):
            sub_cur=cur
            remove = (sub_cur%division)//(division//10)
            sub_cur-=remove*(division//10) # cur에서 각 자리수를 0으로 만듦
            for add in range(10):
                next_num = sub_cur+add*(division//10)
                if next_num<1000:
                    continue
                if next_num in thousand_overset and not visit[next_num]:
                    q.append([next_num, cost+1])
                    visit[next_num]=1
            division*=10        
    if not isReached:
        print('impossible')