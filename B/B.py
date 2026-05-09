def main():
    n,q = input().split()

    n = int(n)
    q = int(q)

    nums = input().split()


    for i in range(len(nums)):
        nums[i] = int(nums[i])


    prefix = [nums[0]]
    
    for i in range(1,len(nums)): 
        prefix.append(nums[i] * prefix[-1])


    for _ in range(q): 
        l,r = input().split()

        l = int(l) -1
        r = int(r) - 1
        
        if l == 0:
            print(prefix[r])
        else:
        
            print(prefix[r] / prefix[l-1])


main()