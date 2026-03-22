

def main():
    n = int(input())
    s = input()
    arr = []
    for i in range(len(s)):
        arr.append(s[i])


    if len(arr) ==1:
        return 1 if s[0] == '#' else 0

    for i in range(n): 
        if arr[i] == '1' or arr[i] == '2':
            arr[i] =  int(arr[i])

    if arr[-1] == 1 and arr[-2] != '#':
        arr[-2] = '#'

    if arr[0] == 1 and arr[1] != '#':
        arr[1] = '#'
    print(arr)

    for i in range(1,n-1):   
        if arr[i] == 1:
            if arr[i-1] == "#" or arr[i+1] =='#':
                continue 
            elif (arr[i-1] == "?") ^ (arr[i+1] == "?"):
                if arr[i+1] == "?":
                    arr[i+1] = '#'
                else:
                    arr[i-1] = '#' 
            else:
                arr[i-1] = '#' 



        elif arr[i] == 2: 
            arr[i-1] = '#'
            arr[i+1] = '#'
        elif arr[i] == '.': 
            if arr[i-1] == '?' or arr[i-1] == '#': 
                arr[i-1] = 'X'
            if arr[i+1] == '?' or arr[i+1] == '#': 
                arr[i+1] = 'X' 


    for i in range(1,n-1):   
        if arr[i] == 1:
            if arr[i-1] == "#" or arr[i+1] =='#':
                continue 
            elif (arr[i-1] == "?") ^ (arr[i+1] == "?"):
                if arr[i+1] == "?":
                    arr[i+1] = '#'
                else:
                    arr[i-1] = '#' 
            else:
                arr[i-1] = '#' 



        elif arr[i] == 2: 
            arr[i-1] = '#'
            arr[i+1] = '#'
        elif arr[i] == '.': 
            if arr[i-1] == '?' or arr[i-1] == '#': 
                arr[i-1] = 'X'
            if arr[i+1] == '?' or arr[i+1] == '#': 
                arr[i+1] = 'X' 
    
    cnt = 0 
    for i in range(n): 
        cnt += 1 if arr[i] == '#' else 0 

    for i in range(1,n-1):
        if type(arr[i]) == int:
            arr[i] -= 1 if arr[i-1] == "#" else 0
            arr[i] -= 1 if arr[i+1] == "#" else 0 

    print(arr)

    return cnt 



print(main())
