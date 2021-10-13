from itertools import combinations
import sys
input = sys.stdin.readline

sizeOfcity, min_ch = map(int, input().split()) # ch: chicken house
posOfch = []
posOfhouse = []
for row in range(sizeOfcity):
    col=0
    for kind in map(int,input().split()):
        if kind==1:
            posOfhouse.append([row, col])
        elif kind==2:
            posOfch.append([row,col])
        col+=1

all_street_dist = [[0 for _ in range(len(posOfch))] for _ in range(len(posOfhouse))] # 집수 x 치킨집수 array
for row in range(len(posOfhouse)):
    h_row, h_col =posOfhouse[row]
    for col in range(len(posOfch)):
        ch_row, ch_col = posOfch[col]
        all_street_dist[row][col] = abs(h_row-ch_row)+abs(h_col-ch_col)

allcase = list(combinations([i for i in range(len(posOfch))], min_ch))
temp_min=float("inf")
min_dist = float("inf")
for case in allcase:
    sumOfdist = 0
    for row in range(len(posOfhouse)):
        for ch in case:
            temp_min=min(temp_min, all_street_dist[row][ch])
        sumOfdist+=temp_min
        temp_min=float("inf")
    min_dist=min(min_dist, sumOfdist)
print(min_dist)