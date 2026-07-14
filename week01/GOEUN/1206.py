for i in range(1,11):
    answer = 0
    N = int(input()) # 건물의 개수 N (4 ≤ N ≤ 1000)
    heights = list(map(int, input().split())) # 건물의 높이들 (0 ≤ 각 건물의 높이 ≤ 255)
    for j in range(len(heights)):
        if heights[j] == 0:
            continue
        pivot = [heights[j-2], heights[j-1], heights[j+1], heights[j+2]]
        max_height = max(pivot)
        if heights[j] - max_height > 0:
            answer += heights[j] - max_height
    print(f"#{i} {answer}")
