T = int(input())
for t in range(1, T+1):
    N = int(input())
    prices = list(map(int, input().split()))
    prices.reverse()
    total_price = 0 # 이득 총합
    max_price = 0
    for price in prices:
        if price >= max_price: # 최댓값 갱신
            max_price = price
        else: # 판매
            total_price += (max_price - price)
    print(f"#{t} {total_price}")