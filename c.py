def main():

    n,m = map(int,input().split())
    mx = 0 

    for i in range(1,n+1):
        x = n // i 
        y = n % i

        if x <= m:
            mx = max(mx, x**i)
        if x +1  <= m:
            mx = max(mx, x**i * y)
        if x +2 <= m:
            mx = max(mx, x**(i-1) * (x-1) * (y +1))



    print(mx)

main()