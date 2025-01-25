#######################################
"""
#######################################
242. Valid Anagram
Solved
Easy
Topics
Companies

Given two strings s and t, return true if t is an
anagram
of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
#######################################
"""
#######################################

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dicta={}
        dictb={}
        for i in s:
            if i not in dicta:
                dicta[i]=1
            else:
                dicta[i]+=1
        for i in t:
            if i not in dictb:
                dictb[i]=1
            else:
                dictb[i]+=1
        if dicta==dictb:
            return True
        else:
            return False
        