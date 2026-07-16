T = int(input())
for t in range(1, T+1):
    H,W = map(int, input().split())
    MAP = [list(input()) for _ in range(H)]
    state = "state"
    for h in range(H):
        for w in range(W):
            if (MAP[h][w] == '^') or (MAP[h][w] == 'v') or (MAP[h][w] == '<') or (MAP[h][w] == '>'):
                x = h
                y = w
                if (MAP[h][w] == '^'):
                    state = 'U'
                elif (MAP[h][w] == 'v'):
                    state = 'D'
                elif (MAP[h][w] == '<'):
                    state = 'L'
                elif (MAP[h][w] == '>'):
                    state = 'R'
    
    N = int(input())
    user_input = input()

    for i in range(N):
        if user_input[i] == 'U':
            state = 'U'
            if ((x - 1) >= 0) and (MAP[x - 1][y] == '.'):
                MAP[x][y] = '.'
                MAP[x - 1][y] = '^'
                x -= 1
            else:
                MAP[x][y] = '^'
        elif user_input[i] == 'D':
            state = 'D'
            if ((x + 1) < H) and (MAP[x + 1][y] == '.'):
                MAP[x][y] = '.'
                MAP[x + 1][y] = 'v'
                x += 1
            else:
                MAP[x][y] = 'v'
        elif user_input[i] == 'L':
            state = 'L'
            if ((y - 1) >= 0) and (MAP[x][y - 1] == '.'):
                MAP[x][y] = '.'
                MAP[x][y - 1] = '<'
                y -= 1
            else:
                MAP[x][y] = '<'

        elif user_input[i] == 'R':
            state = 'R'
            if ((y + 1) < W) and (MAP[x][y + 1] == '.'):
                MAP[x][y] = '.'
                MAP[x][y + 1] = '>'
                y += 1
            else:
                MAP[x][y] = '>'

        elif user_input[i] == 'S':
            if state == 'U':
                for g in range(x - 1, -1, -1):
                    if MAP[g][y] == '*':
                        MAP[g][y] = '.'
                        break
                    elif MAP[g][y] == '#':
                        break
            elif state == 'D':
                for g in range(x + 1, H):
                    if MAP[g][y] == '*':
                        MAP[g][y] = '.'
                        break
                    elif MAP[g][y] == '#':
                        break
            elif state == 'L':
                for g in range(y - 1, -1, -1):
                    if MAP[x][g] == '*':
                        MAP[x][g] = '.'
                        break
                    elif MAP[x][g] == '#':
                        break
            elif state == 'R':
                for g in range(y + 1, W):
                    if MAP[x][g] == '*':
                        MAP[x][g] = '.'
                        break
                    elif MAP[x][g] == '#':
                        break
    
    print(f"#{t} ", end="")
    for h in range(H):
        for w in range(W):
            print(MAP[h][w], end="")
        print()
