n = int(input())
k = int(input())
k_loc = [list(map(int, input().split())) for _ in range(k)]
l = int(input())
l_loc = []
for _ in range(l):
    x, c = input().split()
    l_loc.append([int(x), c])

mat = [[0]*n for _ in range(n)]

for i,j in k_loc:
    mat[i-1][j-1] = 1

pos = [(0,1), (0,-1), (-1,0), (1,0)] # 우, 좌, 상, 하
cnt = 1
x, y = 0,0
sx, sy = pos[0]

def check_pos(sx, sy):
    if (sx,sy) == (0,1):
        return (-1,0), (1,0)
    elif (sx,sy) == (0,-1):
        return (1,0), (-1,0)
    elif (sx,sy) == (1,0):
        return (0,1), (0,-1)
    else:
        return (0,-1), (0,1)

snake = [[0,0]]
while 0 <= x+sx < n and 0 <= y+sy < n:
    if snake[0][0] == snake[-1][0] + sx and snake[0][1] == snake[-1][1] + sy:
        break

    for i, j in l_loc:
        if i == cnt:
            l, r = check_pos(sx, sy)
            if j == 'L':
                sx, sy = l
            else:
                sx, sy = r
            l_loc.pop(0)

    if mat[x+sx][y+sy] == 1: # 사과가 있다면
        snake.append([x+sx, y+sy])
        mat[x+sx][y+sy] = 2
        cnt += 2

    else: # 사과가 없다면
        tx, ty = snake.pop(0)
        mat[tx][ty] = 0
        snake.append([x+sx, y+sy])
        mat[x+sx][y+sy] = 2
        cnt += 1

    x += sx
    y += sy
print(cnt)