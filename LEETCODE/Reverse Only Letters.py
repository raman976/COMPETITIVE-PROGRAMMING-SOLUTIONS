############################################
############################################
'''
917. Reverse Only Letters
Solved
Easy
Topics
Companies
Hint

Given a string s, reverse the string according to the following rules:

    All the characters that are not English letters remain in the same position.
    All the English letters (lowercase or uppercase) should be reversed.

Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"

Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

 

Constraints:

    1 <= s.length <= 100
    s consists of characters with ASCII values in the range [33, 122].
    s does not contain '\"' or '\\'.
'''
############################################
############################################

class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        q=[]
        ind=[]
        p=list(s)
        for i in range(len(s)):
            if 65<=ord(p[i])<=90 or 97<=ord(p[i])<=122:
                q.append(p[i])
                ind.append(i)
        q=q[::-1]
        for i in range(len(ind)):
            p[ind[i]]=q[i]
        return "".join(p)
                
