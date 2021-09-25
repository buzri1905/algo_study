import sys
input = sys.stdin.readline

numOfGate = int(input())
numOfPlane = int(input())
possibleDock = [i for i in range(numOfGate+1)]

def find_gate(try_dock):
    global possibleDock
    if possibleDock[try_dock]==0:
        return -1
    if possibleDock[try_dock]==try_dock:
        possibleDock[try_dock]=possibleDock[try_dock-1]
        return possibleDock[try_dock]
    possibleDock[try_dock] = find_gate(possibleDock[try_dock])
    return possibleDock[try_dock]

numOfDock = 0
for _ in range(numOfPlane):
    try_dock=int(input())
    if find_gate(try_dock)==-1:
        break
    numOfDock+=1
print(numOfDock)