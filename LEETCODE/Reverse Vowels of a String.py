#############################
"""
#############################
345. Reverse Vowels of a String
Solved
Easy
Topics
Companies

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

 

Constraints:

    1 <= s.length <= 3 * 105
    s consist of printable ASCII characters.
#############################
"""
#############################
class Solution:
    def reverseVowels(self, s: str) -> str:
        v=("a","e","i","o","u","A","E","I","O","U")
        q=[]
        u=[]
        count=-1
        for i in s:
            count+=1
            if i in v:
                q.append(i)
                u.append(count)
        q.reverse()
        print(q)
        print(u)
        a=list(s)
        print(a)
        cou=-1
        for i in u:
            cou+=1
            print(i)
            a[i]=q[cou]
        y="".join(a)
        return y
