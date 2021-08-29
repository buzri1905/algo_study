import sys
input = sys.stdin.readline

numOfchu = int(input())
chus = sorted(list(map(int, input().split())))

can_create_weight = 0 # 0~can_create_weight까지 현재 보고있는 추로 조합해서 만들 수 있음
flag=0
for cur_chu in chus:
    if cur_chu>can_create_weight+1: # 현재 만들어야하는 추 수: can_create_weight+1, 다음추가 이거보다 크면 해당 추 못만듦
        break
    else:
        can_create_weight+=cur_chu # 0~can_create_weight만큼 만들수 있고 새로 추가 추가됐으므로 0~can_create_weight+cur_chu만큼 조합으로 생성 가능
print(can_create_weight+1)