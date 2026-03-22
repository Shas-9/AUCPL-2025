

def main(): 
    n = int(input())
    nums = input().split()  
    total = 0 

    if len(nums) == 1: 
        print(0)
        return

    for i in range(n):
        nums[i] = int(nums[i])

    nums.sort()
    prefix = [nums[0]]

    for i in range(1,n):
        prefix.append(nums[i] + prefix[-1])


    for i in range(n): 
        cur =  nums[i]
        if i != 0:
            left = prefix[i-1]
            num_on_left = i
            total += (cur * num_on_left) - left

            

        if i != n -1:
            right = prefix[-1] - prefix[i]

            num_on_right = (n -1) - i

            total += right - (cur * num_on_right)
    print(total//2)
    
    # do 0th and n-1th case last


main()