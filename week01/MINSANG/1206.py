T = 10

for tc in range(1,T+1):
    N = int(input())
    buildings = list(map(int,input().split()))
    
    total_views = 0
    
    for i in range(2,N-2):
        current_height = buildings[i]
        max_around = max(buildings[i-2],buildings[i-1],buildings[i+1],buildings[i+2])
        
        if current_height > max_around:
            total_views += (current_height-max_around)
            
    print(f"#{tc} {total_views}")