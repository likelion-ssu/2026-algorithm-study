from collections import deque

T = int(input())

drow = [-1, 1, 0, 0]
dcol = [0, 0, -1, 1]

for test_case in range(1, T + 1):
    N = int(input())

    maze = []
    visited = [[0] * N for _ in range(N)]

    for i in range(N):
        row = list(map(int, input()))
        maze.append(row)

        for j in range(N):
            if row[j] == 2:
                start = (i, j)

    queue = deque()
    queue.append(start)
    visited[start[0]][start[1]] = 1

    answer = 0

    while queue:
        y, x = queue.popleft()

        if maze[y][x] == 3:
            answer = visited[y][x] - 2
            break

        for d in range(4):
            ny = y + drow[d]
            nx = x + dcol[d]

            if 0 <= ny < N and 0 <= nx < N:
                if maze[ny][nx] != 1 and visited[ny][nx] == 0:
                    visited[ny][nx] = visited[y][x] + 1
                    queue.append((ny, nx))

    print(f"#{test_case} {answer}")