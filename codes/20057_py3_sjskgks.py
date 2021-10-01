import sys
input = sys.stdin.readline

sizeOfsand = int(input())
sand = []
for _ in range(sizeOfsand):
    sand.append(list(map(int, input().split())))
    
def next_pos(direc, cur_row, cur_col):
    if direc=='left':
        return cur_row, cur_col-1
    elif direc=='down':
        return cur_row+1, cur_col
    elif direc=='right':
        return cur_row, cur_col+1
    else:
        return cur_row-1, cur_col

def next_move(cur_direction, numOfmove):
    if cur_direction=='left':
        return 'down', numOfmove
    elif cur_direction=='down':
        return 'right', numOfmove+1
    elif cur_direction=='right':
        return 'up', numOfmove
    else:
        return 'left', numOfmove+1
    
## left<->right: col대칭이므로 col에 음수, left<->up: xy대칭 down<->up: row대칭이므로 row에 음수, dic각 원소는 row, col에 더해지는 값
left_scatter_pos={1:[[-1,1],[1,1]],2:[[-2,0],[2,0]],5:[[0,-2]],7:[[-1,0],[1,0]],10:[[-1,-1],[1,-1]],'reserve':[[0,-1]]}
down_scatter_pos={1:[],2:[],5:[],7:[],10:[],'reserve':[]}
right_scatter_pos={1:[],2:[],5:[],7:[],10:[],'reserve':[]}
up_scatter_pos={1:[],2:[],5:[],7:[],10:[],'reserve':[]}
for percent_value in [1,2,5,7,10,'reserve']:
    for r, c in left_scatter_pos[percent_value]:
        down_scatter_pos[percent_value].append([-c,r])
        right_scatter_pos[percent_value].append([r,-c])
        up_scatter_pos[percent_value].append([c,r])
scatter_pos = {'left':left_scatter_pos, 'down':down_scatter_pos, 'right':right_scatter_pos, 'up':up_scatter_pos}
cur_row, cur_col = sizeOfsand//2, sizeOfsand//2
cur_direc='up'
numOfmove=0
out_sand = 0

while True:
    if not (0<=cur_row<sizeOfsand and 0<=cur_col<sizeOfsand):
        break
    cur_direc, numOfmove = next_move(cur_direc, numOfmove)
    for _ in range(numOfmove):
        cur_row, cur_col = next_pos(cur_direc, cur_row, cur_col) # 공격받은 위치
        onepercent = sand[cur_row][cur_col]*0.01
        scatterOfsand = {1: int(onepercent), 2: int(onepercent*2), 5: int(onepercent*5), 7: int(onepercent*7), 10: int(onepercent*10)}
        scatterOfsand['reserve'] = sand[cur_row][cur_col]-\
            (2*int(onepercent)+2*int(onepercent*2)+int(onepercent*5)+2*int(onepercent*7)+2*int(onepercent*10))
        sand[cur_row][cur_col]=0
        for percent_value, scatter_amount in scatterOfsand.items():
            for r_move, c_move in scatter_pos[cur_direc][percent_value]:
                scattered_row, scattered_col = cur_row+r_move, cur_col+c_move
                if scattered_row<0 or scattered_row>= sizeOfsand or scattered_col<0 or scattered_col>=sizeOfsand:
                    out_sand+=scatter_amount
                    continue
                sand[scattered_row][scattered_col]+=scatter_amount
print(out_sand)