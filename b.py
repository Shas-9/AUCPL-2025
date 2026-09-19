

def main(): 
    n,m = map(int,input().split())
    parts = []
    mx = 0 

    for _ in range(n):
        c,x,r = map(int,input().split())
        # c = $
        # x - times regen
        # r = regen time
        mx = max(mx, x * (r +100) )

        parts.append((c,x,r))


    l = 1
    r = mx

    def can_do(mid,m,parts):
        
        cur = 0
        for c,x,r in parts:
            cur += c * min(x+1, 1 + (mid//r))

        return cur >= m
        

    while l < r:
        mid = l + (r - l ) // 2 

        do = can_do(mid,m,parts)

        if do: 
            r = mid
        else:
            l = mid + 1
    
    if can_do(l,m,parts):
        print(l)
    else:
        print(-1)

main()