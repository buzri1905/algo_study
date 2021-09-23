import sys
input = sys.stdin.readline

numOfGate = int(input())
numOfPlane = int (input())
possibleDock = [i for i in range(numOfGate+1)]
numOfDock = 0
is_full = False
for _ in range(numOfPlane):
    try_dock=int(input())
    if is_full:
        continue
    original_try = try_dock
    while try_dock:
        if possibleDock[try_dock]==try_dock:
            numOfDock+=1
            possibleDock[try_dock]=possibleDock[possibleDock[try_dock-1]]
            possibleDock[original_try]=possibleDock[try_dock]
            break
        try_dock=possibleDock[try_dock]
    if try_dock==0:
        is_full=True
print(numOfDock)