

def main(): 
    nm = input()
    scores = input().split()
    companiers = input().split()

    for i in range(len(scores)): 
        scores[i] = int(scores[i])

    for i in range(len(companiers)): 
        companiers[i] = int(companiers[i])

    scores.sort()

    for i in range(1,len(scores)): 
        scores[i] += scores[i-1]

    for i in range(len(companiers)): 
        idx = 0 
        while idx < len(scores) and scores[idx] <= companiers[i]: 
            idx += 1

        if idx == len(scores):
            idx -=1 
        
        if scores[idx] > companiers[i]: 
            print(idx)
        else:
            print(idx + 1)



main()