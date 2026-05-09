from math import  lcm, gcd




def main(): 

    adj = {}

    n,m = input().split()
    n,m = int(n), int(m)
    
    for i in range(n):
        adj[i+1] = []

    for _ in range(m): 
        start,end = input().split()
        start,end = int(start), int(end)
        if start not in adj: 
            adj[start] = []

        adj[start].append(end)


    res = []
    
    def dfs(node,d, l): 

        if len(adj[node]) == 0:
            res.append((l,d))

        if len(adj[node]) == 1: 
            dfs(adj[node][0], d, l+1)

        elif len(adj[node]) == 2: 
            dfs(adj[node][1], d+1,l+1)
            dfs(adj[node][0], d+1,l+1)

    
    num = 0 
    denom = 1 

    dfs(1,0,0)
    mx = 0 
    for a,b in res: 
        mx = max(mx,b)


    for a,b in res: 
        num += a * 2**(mx - b)
    denom = 2**mx
    g = gcd(num,mx)

    num //= g 
    denom //= g        
    print(f'{num}/{denom}')


main()
