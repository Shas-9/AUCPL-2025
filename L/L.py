def main():

    scores = input().split()

    for i in range(len(scores)):
        scores[i] = int(scores[i])

    n = int(input())

    mx_score = -float('inf')
    mx_word = ''

    for _ in range(n):
        word = input()
        u = len(set(list(word)))
        score = 0 

        for i in range(len(word)):
            score += (scores[ord(word[i]) - ord('a')] * (6 - u))
        
        if score > mx_score:
            mx_score = score
            mx_word = word

        if mx_score == score and word < mx_word:
            mx_word = word
    
    print(mx_word)

main()