from collections import deque

def main(): 
    n,k,t,s = input().split()
    
    n,k,t,s = int(n),int(k), int(t), int(s)
        
    arr = input().split()


    for i in range(len(arr)): 
        arr[i] = int(arr[i])

    q = deque()
    in_q = 0
    cnt = 0 
    i = 0 

    while i < len(arr):
        while q and q[0][0] <= (i - t): 
            d,c = q.popleft()
            in_q -= c

        if in_q + arr[i] >= k: 
            in_q = 0
            q = deque()

            cnt += 1
            i = i + s
        else: 
            q.append((i,arr[i]))
            in_q += arr[i]
            i+=1
        
    print(cnt)

main()