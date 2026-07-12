t = int(input())

for i in range(t) :
    day_amt = int(input())

    arr = list(map(int, input().split()))
    res = 0
    max_price = arr[day_amt - 1]

    for j in range(day_amt - 2, -1, -1) :
        if(arr[j] < max_price) :
            res += max_price - arr[j];
        else :
            max_price = arr[j];

    print("#%d %d"  % (i + 1, res))