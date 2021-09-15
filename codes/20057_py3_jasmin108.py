T = int(input())
mat = []
for _ in range(T):
    temp = list(map(float, input().split()))
    mat.append(temp)

iter= []
for i in range(1, T):
    for _ in range(2):
        iter.append(i)
iter.append(T-1)


dir = [(0, -1), (1, 0), (0, 1), (-1, 0)] * T
weight = [0.02, 0.07, 0.07, 0.02, 0.01, 0.01, 0.1, 0.1, 0.05, 0.55]
left = [(-2, 0), (-1, 0), (1, 0), (2, 0), (-1, 1), (1, 1), (-1, -1), (1, -1), (0, -2), (0, -1)]
right= [(-2, 0), (-1,0), (1, 0), (2, 0), (-1, -1), (1, -1), (-1, 1), (1, 1), (0, 2), (0, 1)]
up   = [(0, -2), (0, -1), (0, 1), (0, 2), (1, -1), (1, 1), (-1, -1), (-1, 1), (-2, 0), (-1, 0)]
down = [(0, -2), (0, -1), (0, 1), (0, 2), (-1, -1), (-1, 1), (1, -1), (1, 1), (2, 0), (1, 0)]


x,y = T//2, T//2
final = 0


def push_sand(dir_name, x, y):
    ans = 0
    for (i, j), w in zip(dir_name, weight):
        if (x+i >= 0) and (x+i < T) and (y+j >= 0) and (y+j < T):
            mat[x+i][y+j] += mat[x][y] * w
        else:
            ans += mat[x][y] * w
    mat[x][y] = 0
    return mat, ans


while x != 0 and y != 0:
    for i, (sx,sy) in zip(iter, dir):
        for _ in range(i):
            x += sx
            y += sy
            if (sx,sy) == dir[0]: # left
                mat, ans = push_sand(left, x, y)
            elif (sx,sy) == dir[1]: # down
                mat, ans = push_sand(down, x, y)
            elif (sx,sy) == dir[2]: # right
                mat, ans = push_sand(right, x, y)
            else: # up
                mat, ans = push_sand(up, x, y)

            final += ans

print(final)