T = int(input())

for tc in range(1, T + 1):
    H, W = map(int, input().split())

    # H행 W열 크기의 2차원 리스트 만들기
    game_map = [[0] * W for _ in range(H)]

    # 전차 위치
    r = 0
    c = 0

    # 맵 입력
    for i in range(H):
        s = input()

        for j in range(W):
            game_map[i][j] = s[j]

            # 전차 위치 찾기
            if game_map[i][j] in ['^', 'v', '<', '>']:
                r = i
                c = j

    N = int(input())
    cmd = input()

    for i in range(N):

        if cmd[i] == 'U':
            game_map[r][c] = '^'

            nr = r - 1
            nc = c

            if nr >= 0 and game_map[nr][nc] == '.':
                game_map[r][c] = '.'

                r = nr
                c = nc

                game_map[r][c] = '^'

        elif cmd[i] == 'D':
            game_map[r][c] = 'v'

            nr = r + 1
            nc = c

            if nr < H and game_map[nr][nc] == '.':
                game_map[r][c] = '.'

                r = nr
                c = nc

                game_map[r][c] = 'v'

        elif cmd[i] == 'L':
            game_map[r][c] = '<'

            nr = r
            nc = c - 1

            if nc >= 0 and game_map[nr][nc] == '.':
                game_map[r][c] = '.'

                r = nr
                c = nc

                game_map[r][c] = '<'

        elif cmd[i] == 'R':
            game_map[r][c] = '>'

            nr = r
            nc = c + 1

            if nc < W and game_map[nr][nc] == '.':
                game_map[r][c] = '.'

                r = nr
                c = nc

                game_map[r][c] = '>'

        elif cmd[i] == 'S':
            br = r
            bc = c

            while True:

                if game_map[r][c] == '^':
                    br -= 1

                elif game_map[r][c] == 'v':
                    br += 1

                elif game_map[r][c] == '<':
                    bc -= 1

                elif game_map[r][c] == '>':
                    bc += 1

                # 맵 밖으로 나가면 종료
                if br < 0 or br >= H or bc < 0 or bc >= W:
                    break

                # 벽돌 벽이면 부수고 종료
                if game_map[br][bc] == '*':
                    game_map[br][bc] = '.'
                    break

                # 강철 벽이면 종료
                if game_map[br][bc] == '#':
                    break

    print(f"#{tc}", end=" ")

    for i in range(H):
        for j in range(W):
            print(game_map[i][j], end="")

        print()