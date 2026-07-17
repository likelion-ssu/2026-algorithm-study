T = int(input())

for test_case in range(1, T + 1):
    H, W = map(int, input().split())
    game = []

    for i in range(H):
        row = list(input())
        game.append(row)
        for j in range(W):
            if row[j] in "^v<>":
                r, c = i, j

    N = int(input())
    orders = input()

    for order in orders:
        if order == 'U':
            game[r][c] = '^'
            if r > 0 and game[r - 1][c] == '.':
                game[r][c] = '.'
                r -= 1
                game[r][c] = '^'
        elif order == 'D':
            game[r][c] = 'v'
            if r < H - 1 and game[r + 1][c] == '.':
                game[r][c] = '.'
                r += 1
                game[r][c] = 'v'
        elif order == 'L':
            game[r][c] = '<'
            if c > 0 and game[r][c - 1] == '.':
                game[r][c] = '.'
                c -= 1
                game[r][c] = '<'
        elif order == 'R':
            game[r][c] = '>'
            if c < W - 1 and game[r][c + 1] == '.':
                game[r][c] = '.'
                c += 1
                game[r][c] = '>'

        elif order == 'S':
            if game[r][c] == '^':
                nr = r - 1
                while nr >= 0:
                    if game[nr][c] == '#':
                        break
                    if game[nr][c] == '*':
                        game[nr][c] = '.'
                        break
                    nr -= 1
            elif game[r][c] == 'v':
                nr = r + 1
                while nr < H:
                    if game[nr][c] == '#':
                        break
                    if game[nr][c] == '*':
                        game[nr][c] = '.'
                        break
                    nr += 1
            elif game[r][c] == '<':
                nc = c - 1
                while nc >= 0:
                    if game[r][nc] == '#':
                        break
                    if game[r][nc] == '*':
                        game[r][nc] = '.'
                        break
                    nc -= 1
            else:
                nc = c + 1
                while nc < W:
                    if game[r][nc] == '#':
                        break
                    if game[r][nc] == '*':
                        game[r][nc] = '.'
                        break
                    nc += 1

    print(f"#{test_case}")
    for row in game:
        print("".join(row))