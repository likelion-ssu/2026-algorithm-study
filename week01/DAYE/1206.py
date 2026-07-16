for test_case in range(1, 11):
    N = int(input())
    h = list(map(int, input().split()))
 
    answer = 0
 
    for i in range(2, N - 2):
        max_height = max(
            h[i - 2],
            h[i - 1],
            h[i + 1],
            h[i + 2]
        )
 
        if h[i] > max_height:
            answer += h[i] - max_height
 
    print(f"#{test_case} {answer}")