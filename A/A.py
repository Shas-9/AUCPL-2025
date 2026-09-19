from heapq import heappop, heappush

def main(): 


    n,t,i = input().split()
    n,t,i = int(n), int(t), int(i)
    # n 
    # t = mins
    # i = inital pos 


    left = []
    right = []

    arr = [True] * n

    for j in range(i-1): 
        left.append(j+1)
    for j in range(i,n): 
        right.append(j+1)

    right = right[::-1]

    for _ in range(t): 
        command = input()

        if command == 'C': 
            arr[i-1] = False

        elif command == 'L': 
            if len(left) == 0: 
                continue 

            if arr[i-1] == True:
                right.append(i)

            i = left.pop()

        elif command == 'R':
            if len(right) == 0: 
                continue 

            if arr[i-1] == True:
                left.append(i)

            i = right.pop()

        elif command == 'QL': 
            if len(left) == 0: 
                print(-1)
            
            else: 
                print(left[-1])

        else:
            if len(right) == 0: 
                print(-1)

            else: 
                print(right[-1])

main()