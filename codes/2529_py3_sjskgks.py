import sys
from itertools import permutations
input = sys.stdin.readline

numOfsign = int(input())
sign = input().split()
num_list = list(permutations([i for i in range(0,10)], numOfsign+1))
able_num = []
for permu in num_list:
    flag = 0
    for signal in range(len(sign)):
        if sign[signal] == '<' and not permu[signal] < permu[signal+1]:
            flag = 1
            break
        elif sign[signal] == '>' and not permu[signal] > permu[signal+1]:
            flag = 1
            break
    if flag:
            continue
    able_num.append(permu)
max_num = ''
min_num = ''
for i in able_num[-1]:
    max_num+=str(i)
for i in able_num[0]:
    min_num+=str(i)
print(max_num)
print(min_num)
