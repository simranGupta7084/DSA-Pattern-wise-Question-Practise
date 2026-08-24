class Solution:
    def reverseWords(self, s: str) -> str:
        word = s.split()

        l = 0
        r = len(word)-1

        while l<r:
            word[l],word[r] = word[r],word[l]

            l+=1
            r-=1

        return " ".join(word)

        

        