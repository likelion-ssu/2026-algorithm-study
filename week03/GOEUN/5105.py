from collections import deque

T = int(input())
for t in range(1, T+1):
    N = int(input())
    MAP = [list(map(int, input())) for _ in range(N)]
    for r in range(N):
        for c in range(N):
            if MAP[r][c] == 2: # 출발점 저장(row, col)
                row = r
                col = c

    drow = [-1, 1, 0, 0]
    dcol = [0, 0, -1, 1]

    answer = 0
    found = False

    queue = deque()
    queue.append((row, col, 0)) # 행, 열, 거리(시작점에서 얼마나 갔는지)
    visited = deque() # 방문한 칸 기록용
    visited.append((row, col))
    while queue:
        row, col, dist = queue.popleft()

        for i in range(4): # 상하좌우 탐색하며 통로 찾기
            new_row = row + drow[i]
            new_col = col + dcol[i]
            if (new_row >= 0 and new_row < N and new_col >= 0 and new_col < N) and (MAP[new_row][new_col] != 1) and ((new_row, new_col) not in visited): # 미로 범위 내에 있는지, 벽이 아닌지, 방문하지 않은 곳인지 확인
                if MAP[new_row][new_col] == 3: # 해당 칸이 도착점
                    answer = dist
                    found = True
                    break
                else: # 해당 칸은 통로(0) -> 이동
                    visited.append((new_row, new_col))
                    queue.append((new_row, new_col, dist + 1))

        if found == True:
            break

    print(f"#{t} {answer}")