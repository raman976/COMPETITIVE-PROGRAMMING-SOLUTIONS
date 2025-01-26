###############################################
"""
###############################################
383. Ransom Note
Solved
Easy
Topics
Companies

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

 

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.
###############################################
"""
###############################################


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dicta={}
        dictb={}
        dictr={}
        for i in ransomNote:
            if i not in dictr:
                dictr[i]=1
            else:
                dictr[i]+=1
        for i in magazine:
            if i not in dictb:
                dictb[i]=1
            else:
                dictb[i]+=1
        a=set(ransomNote)
        for i in a:
            if i in dictb:
                dicta[i]=dictb[i]
        f=True
        if len(dictr)!=len(dicta):
            return False
        for i in dicta:
            if dictr[i]>dicta[i]:
                f=False
        return f