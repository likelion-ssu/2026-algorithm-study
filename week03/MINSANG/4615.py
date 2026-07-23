# 8방향 탐색 (상, 하, 좌, 우, 좌상, 우상, 좌하, 우하)
dr = [-1, 1, 0, 0, -1, -1, 1, 1]
dc = [0, 0, -1, 1, -1, 1, -1, 1]

# T: 전체 테스트 케이스 수 입력
T = int(input())

for tc in range(1, T + 1):
    N, M = map(int, input().split())
    
    # 1. N x N 크기의 보드판을 0으로 초기화 (0: 빈칸, 1: 흑돌, 2: 백돌)
    board = [[0] * N for _ in range(N)]
    
    # 2. 초기 돌 4개 세팅 (정중앙 엇갈린 배치)
    mid = N // 2
    board[mid - 1][mid - 1] = 2  # 백돌
    board[mid][mid] = 2          # 백돌
    board[mid - 1][mid] = 1      # 흑돌
    board[mid][mid - 1] = 1      # 흑돌
    
    # 3. M번의 턴 동안 돌 놓기 및 뒤집기 진행
    for _ in range(M):
        # 입력: x(열), y(행), color
        x, y, color = map(int, input().split())
        
        # 0-based 인덱스로 변환 (r: 행, c: 열)
        r, c = y - 1, x - 1
        board[r][c] = color  # 일단 돌을 놓음
        
        # 8방향 각각 탐색
        for d in range(8):
            nr = r + dr[d]
            nc = c + dc[d]
            
            flip_candidates = []  # 뒤집을 후보 좌표들을 담을 장바구니
            
            # 보드 범위 안에서 한 칸씩 직진
            while 0 <= nr < N and 0 <= nc < N:
                if board[nr][nc] == 0:
                    # 빈칸을 만나면 샌드위치가 안 되므로 뒤집기 취소(버림)
                    break
                    
                elif board[nr][nc] != color:
                    # 상대방 돌이면 장바구니에 담고 계속 직진
                    flip_candidates.append((nr, nc))
                    
                elif board[nr][nc] == color:
                    # 내 돌을 만나면 샌드위치 완성!
                    # 장바구니에 담아둔 상대 돌들을 전부 내 색으로 뒤집기
                    for fr, fc in flip_candidates:
                        board[fr][fc] = color
                    break  # 뒤집기 성공했으므로 이 방향 탐색 종료
                
                # 같은 방향으로 한 칸 더 직진
                nr += dr[d]
                nc += dc[d]
                
    # 4. 최종 흑돌(1)과 백돌(2) 개수 세기
    black_cnt = 0
    white_cnt = 0
    for row in range(N):
        for col in range(N):
            if board[row][col] == 1:
                black_cnt += 1
            elif board[row][col] == 2:
                white_cnt += 1
                
    # 결과 출력
    print(f"#{tc} {black_cnt} {white_cnt}")