from collections import deque
N = int(input())
mat = [[0]*N for _ in range(N)]

for _ in range(int(input())):
    i, j = map(int, input().split())
    mat[i-1][j-1] = 1

dir_dict = {}
for _ in range(int(input())):
    x, c = input().split()
    dir_dict[int(x)] = c

pos = [(0,-1), (1,0), (0,1), (-1,0)] # 좌, 하, 우, 상

cur_dir = 2 # 우
x,y = 0, 0

snake = deque([[0, 0]])

cnt = 0
while True:
    curr_pos = pos[cur_dir]
    x += curr_pos[0]
    y += curr_pos[1]

    if not(0 <= x < N and 0 <= y < N):
        break

    if [x,y] in snake:
        break

    if mat[x][y] == 0:
        del_x, del_y = snake.popleft()
        mat[del_x][del_y] = 0
    mat[x][y] = 2
    snake.append([x, y])
    cnt += 1

    if cnt in dir_dict.keys():
        new_dir = dir_dict[cnt]
        if new_dir == 'L':
            cur_dir = (cur_dir+1)%4
        else:
            cur_dir = (cur_dir+3)%4
        curr_pos = pos[cur_dir]

print(cnt+1)
