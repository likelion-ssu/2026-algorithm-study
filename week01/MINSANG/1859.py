T = int(input())
for tc in range(1,1+T):
    N = int(input())
    prices = list(map(int, input().split()))
    
    max_price = 0
    total_profit = 0
    
    for price in reversed(prices):
        if price > max_price:
            max_price = price
        else:
            total_profit += (max_price-price)
        
    print(f"#{tc} {total_profit}")
        