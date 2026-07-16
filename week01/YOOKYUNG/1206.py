for tc in range(1, 11):
    N = int(input())
    arr = list(map(int, input().split()))

    result = 0

# 처음부터 하지 않는 이유 : 처음은 필요 없음 N-2
    for i in range(2, N - 2):
        diff = arr[i] - max(arr[i-2], arr[i-1], arr[i+1], arr[i+2])

        if diff > 0:
            result += diff

    print(f"#{tc} {result}")