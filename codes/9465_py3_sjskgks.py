import sys
input = sys.stdin.readline

for case in range(int(input())):
    numOfsticker = int(input())
    top = list(map(int, input().split()))
    bottom = list(map(int, input().split()))
    max_list = [[0,0],[0,0]] # 스티커 탐색순서 좌->우, max_list[0]: bottom, max_list[1]: top
                             # max_list[0][1]: bottom의 이전, max_list[0][0]:bottom의 이전의 이전
    for cur in range(numOfsticker):
        cur_top = top[cur]+max(max_list[0][1], max_list[0][0])
        cur_bottom = bottom[cur]+max(max_list[1][1], max_list[1][0])
        max_list[1] = [max_list[1][1], cur_top]
        max_list[0] = [max_list[0][1], cur_bottom]
    print(max(max(max_list[0]), max(max_list[1])))