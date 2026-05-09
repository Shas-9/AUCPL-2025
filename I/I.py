
class NODE: 
    def __init__(self): 
        self.val = 0 
        self.num = 0 
        self.children = []

        self.t = 0 


def bin_seach(arr,tar): 
    l = 0 
    r = len(arr) -1

    while l < r: 
        mid = l + ((r-l) //2)

        if arr[mid] < tar: 
            l = mid + 1

        elif arr[mid] > tar:
            r = mid
        else:
            return arr[mid]

    
    return arr[r] if arr[r] >= tar else -1 

def main():
    n = int(input())
    nodes = [NODE() for _ in range(n)] 
    mp  = {}

    for i in range(len(nodes)):
        nodes[i].num = i

    for _ in range(n-1): 
        s,e,p = input().split()
        s,e,p = int(s), int(e), int(p)

        # s - start
        # e - end
        # p - reley 
        
        nodes[s].children.append(nodes[e])

        nodes[e].val = p 

    arr = []


    def dfs(node):
        if len(node.children) == 0: 
            return node.val

        t = 0 

        for i in range(len(node.children)): 
            t += dfs(node.children[i])
    
    
        arr.append(t)
        node.t = t
        return t + node.val


    arr.append(dfs(nodes[0]))

    arr = list(set(arr))
    arr.sort() 
    mx = arr[-1]



    for i in range(len(nodes)-1,-1,-1): 
        if nodes[i].t not in mp: 
            mp[nodes[i].t] = nodes[i].num
        else: 
            mp[nodes[i].t] = min(nodes[i].num,mp[nodes[i].t])
    
    x = int(input())

    for _ in range(x):
        tar = int(input())
        res = bin_seach(arr,tar)

        if tar > mx: 
            print(-1)
        else: 
            print(mp[res])

main()
