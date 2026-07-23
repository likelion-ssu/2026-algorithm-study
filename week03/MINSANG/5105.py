from collections import deque

# 1. 4방향 이동을 위한 화살표 (위, 아래, 왼쪽, 오른쪽)
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    
    # 2. 미로 보드판 입력받기
    maze = [list(map(int, input())) for _ in range(N)]

    # 3. 출발점(숫자 2)의 좌표(행, 열) 찾기
    start_r, start_c = -1, -1
    for i in range(N):
        for j in range(N):
            if maze[i][j] == 2:
                start_r, start_c = i, j
                break

    # 4. BFS(너비 우선 탐색) 준비
    # 큐(대기열) 생성: (현재 행, 현재 열, 지금까지 지난 0의 개수)
    q = deque([(start_r, start_c, 0)])
    
    # 방문 체크용 표 만들기 (이미 갔던 곳 다시 안 가기 위함)
    visited = [[False] * N for _ in range(N)]
    visited[start_r][start_c] = True  # 출발점 방문 표시

    ans = 0  # 정답(최소 거리)을 저장할 변수 (기본값 0)

    # 5. 줄 서있는 대기열(q)이 비어있지 않은 동안 계속 탐색
    while q:
        # 대기열 맨 앞에 있는 칸을 하나 꺼냄
        r, c, dist = q.popleft()

        # 꺼낸 칸에서 상, 하, 좌, 우 4방향 살펴보기
        for d in range(4):
            nr = r + dr[d]
            nc = c + dc[d]

            # 조건 1: 미로 안이고, 아직 안 가본 칸인가?
            if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                
                # 상황 A: 다음 칸이 도착점(3)인 경우
                if maze[nr][nc] == 3:
                    ans = dist  # 지금까지 거쳐온 0의 개수(dist)가 바로 정답
                    q.clear()   # 탐색 완료했으니 큐를 비워서 while문 탈출
                    break

                # 상황 B: 다음 칸이 갈 수 있는 길(0)인 경우
                elif maze[nr][nc] == 0:
                    visited[nr][nc] = True        # 방문했다고 표시
                    q.append((nr, nc, dist + 1))  # '거리+1' 해서 다음 대기열 줄 맨 뒤에 세움

    print(f"#{tc} {ans}")