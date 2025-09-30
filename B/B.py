def main():
    h,w = input().split()
    h = int(h)
    w = int(w)

    map = []

    for _ in range(h):
        inp = input()
        map.append([])

        for i in range(w):
            if inp[i] != '*' and inp[i] != ".":
                map[-1].append(float(inp[i]))
            else:
                map[-1].append(inp[i])


    
    for i in range(w):
        if map[-1][i] == '.' or map[-1][i] == '*':
            map[-1][i] = 0.0

    # pprint.pprint(map)


    for r in range(h-2,-1,-1):
        for c in range(w): 
            if map[r][c] == '.':
                map[r][c] = map[r+1][c]
            elif map[r][c] == '*':
                # print(r,w)
                # print(map)
                sm = (map[r+1][c+1] +  map[r+1][c-1])
                map[r][c] =  sm/ 2 if sm != 0 else 0
            else:
                map[r][c] = float(map[r][c])

    mx = -float('inf')
    mx_idx = -1

    for i in range(w):
        if map[0][i] >mx:
            mx = map[0][i]
            mx_idx = i

    print(f'{mx:.7f} ')
    print(mx_idx+1)


main()