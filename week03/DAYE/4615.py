T = int(input())

drow = [-1, -1, -1, 0, 0, 1, 1, 1]
dcol = [-1, 0, 1, -1, 1, -1, 0, 1]

for test_case in range(1, T + 1):
    N, M = map(int, input().split())
    
    # 초기 보드판 설정
    board = [[0] * N for _ in range(N)]
    mid = N // 2
    board[mid - 1][mid - 1] = 2
    board[mid][mid] = 2
    board[mid - 1][mid] = 1
    board[mid][mid - 1] = 1

    # 돌놓기 M번반복
    for _ in range(M):
        x, y, color = map(int, input().split())
        x -= 1
        y -= 1

        board[y][x] = color
        enemy = 2 if color == 1 else 1

        for d in range(8):
            ny = y + dcol[d]
            nx = x + drow[d]
            temp = []

            while 0 <= ny < N and 0 <= nx < N:
                if board[ny][nx] == 0:
                    break

                if board[ny][nx] == enemy:
                    temp.append((ny, nx))
                elif board[ny][nx] == color:
                    for ty, tx in temp:
                        board[ty][tx] = color
                    break
                else:
                    break

                ny += dcol[d]
                nx += drow[d]

    black = 0
    white = 0

    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                black += 1
            elif board[i][j] == 2:
                white += 1

    print(f"#{test_case} {black} {white}")