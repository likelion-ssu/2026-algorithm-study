dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

T = int(input())

for tc in range(1,T+1):
    N = int(input())

    maze = [list(map(int, input())) for _ in range(N)]