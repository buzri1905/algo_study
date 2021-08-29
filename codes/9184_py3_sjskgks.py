import sys
input = sys.stdin.readline

def memoization(a, b, c):
    if log[a][b][c]!=-1:
        pass
    elif a==0 or b==0 or c==0:
        log[a][b][c]=1
    elif a<b and b<c:
        log[a][b][c]=memoization(a,b,c-1)+memoization(a,b-1,c-1)-memoization(a,b-1,c)
    else:
        log[a][b][c]=memoization(a-1,b,c)+memoization(a-1,b-1,c)+memoization(a-1,b,c-1)-memoization(a-1,b-1,c-1)
    return log[a][b][c]
        
                    
log = [[[-1 for _ in range(21)] for _ in range(21)] for _ in range(21)]
while True:
    a, b, c = map(int,input().split())
    sub_a, sub_b, sub_c = a, b, c
    if a==-1 and b==-1 and c==-1:
        break
    if a<=0 or b<=0 or c<=0:
        sub_a, sub_b, sub_c = 0, 0, 0
    else:
        if a>20 or b>20 or c>20:
            sub_a, sub_b, sub_c = 20, 20, 20
    print('w({:d}, {:d}, {:d}) = {:d}'.format(a, b, c, memoization(sub_a,sub_b,sub_c)))