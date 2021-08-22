import sys
input = sys.stdin.readline

log = [[[0 for _ in range(21)] for _ in range(21)] for _ in range(21)]
for a in range(21):
    for b in range(21):
        for c in range(21):
            if a==0 or b==0 or c==0:
                log[a][b][c]=1
            elif a<b and b<c:
                log[a][b][c]=log[a][b][c-1]+log[a][b-1][c-1]-log[a][b-1][c]
            else:
                log[a][b][c]=log[a-1][b][c]+log[a-1][b-1][c]+log[a-1][b][c-1]-log[a-1][b-1][c-1]

while True:
    a, b, c = map(int,input().split())
    if a==-1 and b==-1 and c==-1:
        break
    if a<=0 or b<=0 or c<=0:
        answer = 1
    elif a>20 or b>20 or c>20:
        answer = log[20][20][20]
    else:
        answer = log[a][b][c]
    print('w({:d}, {:d}, {:d}) = {:d}'.format(a, b, c, answer))