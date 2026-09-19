from copy import deepcopy






def main():
    n = int(input())
    s,t = input().split()
    s = list(s)
    t = list(t)
    f = deepcopy(s) 

    for i in range(n): 
        if ord(s[i]) < ord(t[i]) -1:
            f[i] = chr(ord(t[i]) -1) 
            break

    # print(''.join(s) < ''.join(f) < ''.join(t))

    print(''.join(f))
main()
    

