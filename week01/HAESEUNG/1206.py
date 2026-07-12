for t in range(10) :
    building_amt = int(input())

    arr = []
    res = 0

    arr = list(map(int, input().split()))

    for i in range(2, building_amt - 2) :
        cur_height = arr[i]

        left_max = max(arr[i - 1], arr[i - 2])
        right_max = max(arr[i + 1], arr[i + 2])

        tmp = cur_height - max(left_max, right_max)

        if(tmp < 0) :
            tmp = 0
        
        res += tmp

    print("#%d %d" % (t + 1, res))


        





