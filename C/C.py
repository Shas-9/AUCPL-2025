


def main():
    total = [0] 
    s = input()

    def backtrack(i,num):


        if i == len(s): 
            total[0] += num
        
        else:
            num *= 10
            if s[i] == '*': 
                for m in range(0,10): 
                    backtrack(i+1, num + m)
                
            else:
                backtrack(i+1, num + int(s[i]))

    
    backtrack(0,0)
    print(total[0])



main()