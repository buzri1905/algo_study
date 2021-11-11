from itertools import product
import sys
input = sys.stdin.readline

numOfvar, numOfclause = map(int, input().split())
case = [[1, -1] for _ in range(numOfvar)] # 양수면 true 음수면 false
all_case = list(product(*case))
function_ = []
for _ in range(numOfclause):
    function_.append(list(map(int, input().split())))
    
all_true=False
for th_case in all_case:
    numOftrue=0
    for cal in function_:
        left = th_case[abs(cal[0])-1]*cal[0] # 곱이 양수면 true, 음수면 false
        right = th_case[abs(cal[1])-1]*cal[1]
        if left>0 or right>0:
            numOftrue+=1
        else:
            break
    if numOftrue==numOfclause:
        all_true=True
        break
if all_true:
    print(1)
else:
    print(0)   