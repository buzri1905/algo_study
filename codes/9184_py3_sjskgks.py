import sys
input = sys.stdin.readline

def memoization(a, b, c):
    if a<=0 or b<=0 or c<=0:
        a, b, c = 0, 0, 0
    elif a>20 or b>20 or c>20:
        a, b, c = 20, 20, 20
    
    if log[a][b][c]!=-1:
        return log[a][b][c]
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
    if a==-1 and b==-1 and c==-1:
        break
    print('w({:d}, {:d}, {:d}) = {:d}'.format(a, b, c, memoization(a,b,c)))