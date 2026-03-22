

def main():
    num_steps = int(input())
    matrix = []
    incompatabilities = set()

    for _ in range(num_steps):
        num_manfucatorers = int(input())
        manufactorers = []
        for _ in range(num_manfucatorers):

            name, cost = input().split()
            cost = int(cost)   
            manufactorers.append((name, cost))
        matrix.append(manufactorers)
    
    num_incompatabilities = int(input())
    for _ in range(num_incompatabilities):
        a,b = input().split()
        incompatabilities.add((a,b))
        incompatabilities.add((b,a))

    

    memo = {}

    def dp(i,last):

        if i == len(matrix):
            return 0 

        if (i,last) in memo:
            return memo[(i,last)]

        mn = float('inf')
        
        for name,cost in matrix[i]: 
            if (name,last) in incompatabilities:
                continue
            mn = min(mn, cost + dp(i+1,name)
            )
        memo[(i,last)] = mn
        return memo[(i,last)]
    return dp(0,None)




print(main())