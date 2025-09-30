def main():

    n = int(input())
    arr = input().split()

    for i in range(len(arr)):
        arr[i] = int(arr[i])

    prefix = []
    prefix.append(arr[0])

    for i in range(1,len(arr)):
        prefix.append(arr[i] + prefix[-1])

    min_diff = float('inf')
    ans = None

    for i in range(n-1):
        left_avg = prefix[i] / (i+1)
        right_avg = (prefix[-1] - prefix[i]) / (n-(i+1))
        # print(i)
        # print(left_avg)
        # print(right_avg)
        # print(f' {i+1} - {(left_avg/right_avg)}')

        if abs((left_avg/right_avg) -1) < min_diff:
            min_diff = abs((left_avg/right_avg) -1)
            ans = i
    

    print(ans+1)

main()