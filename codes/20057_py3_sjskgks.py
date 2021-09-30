import sys
input = sys.stdin.readline

sizeOfsand = int(input())
sand = []
for _ in range(sizeOfsand):
    sand.append(list(map(int, input().split())))
    
def Next_pos(direc, cur_row, cur_col):
    if direc=='left':
        return cur_row, cur_col-1
    elif direc=='down':
        return cur_row+1, cur_col
    elif direc=='right':
        return cur_row, cur_col+1
    else:
        return cur_row-1, cur_col

def Next_move(cur_direction, numOfmove):
    if cur_direction=='left':
        return ['down', numOfmove]
    elif cur_direction=='down':
        return ['right', numOfmove+1]
    elif cur_direction=='right':
        return ['up', numOfmove]
    else:
        return ['left', numOfmove+1]
    
def Scatter(row, col): # 공격받은 위치
    onepercent = sand[row][col]*0.01
    reserve = sand[row][col] - (2*int(onepercent)+2*int(onepercent*2)+int(onepercent*5)+2*int(onepercent*7)+2*int(onepercent*10))
    return {1: int(onepercent), 2: int(onepercent*2), 5: int(onepercent*5), 7: int(onepercent*7), 10: int(onepercent*10), 'reserve': reserve}
    
## left<->right: col대칭이므로 col에 음수, left<->up: xy대칭 down<->up: row대칭이므로 row에 음수, dic각 원소는 row, col에 더해지는 값
left_scatter_pos={1:[[-1,1],[1,1]],2:[[-2,0],[2,0]],5:[[0,-2]],7:[[-1,0],[1,0]],10:[[-1,-1],[1,-1]],'reserve':[[0,-1]]}
down_scatter_pos={1:[],2:[],5:[],7:[],10:[],'reserve':[]}
right_scatter_pos={1:[],2:[],5:[],7:[],10:[],'reserve':[]}
up_scatter_pos={1:[],2:[],5:[],7:[],10:[],'reserve':[]}
for param in [1,2,5,7,10,'reserve']:
    for r, c in left_scatter_pos[param]:
        down_scatter_pos[param].append([-c,r])
        right_scatter_pos[param].append([r,-c])
        up_scatter_pos[param].append([c,r])
scatter_pos = {'left':left_scatter_pos, 'down':down_scatter_pos, 'right':right_scatter_pos, 'up':up_scatter_pos}
cur_row, cur_col = sizeOfsand//2, sizeOfsand//2
cur_direc='up'
numOfmove=0
out_sand = 0

while True:
    if cur_row==0 and cur_col==-1:
        break
    cur_direc, numOfmove = Next_move(cur_direc, numOfmove)
    scatter_param = scatter_pos[cur_direc]
    for _ in range(numOfmove):
        cur_row, cur_col = Next_pos(cur_direc, cur_row, cur_col) # 공격받은 위치
        scatterOfsand = Scatter(cur_row, cur_col)
        sand[cur_row][cur_col]=0
        for distribution in [1, 2, 5, 7, 10, 'reserve']:
            scatter = scatterOfsand[distribution]
            for r_param, c_param in scatter_param[distribution]:
                distributed_row, distributed_col = cur_row+r_param, cur_col+c_param
                if distributed_row<0 or distributed_row>= sizeOfsand or distributed_col<0 or distributed_col>=sizeOfsand:
                    out_sand+=scatter
                    continue
                sand[distributed_row][distributed_col]+=scatter
print(out_sand)