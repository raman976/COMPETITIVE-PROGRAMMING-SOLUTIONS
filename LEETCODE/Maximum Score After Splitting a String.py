#########################################################
#########################################################
'''
1422. Maximum Score After Splitting a String
Solved
Easy
Topics
Companies
Hint

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

Example 3:

Input: s = "1111"
Output: 3

 

Constraints:

    2 <= s.length <= 500
    The string s consists of characters '0' and '1' only.


'''
#########################################################
#########################################################

import math
class Solution:
    def maxScore(self, s: str) -> int:
        pre=[[0,0]]
        count1=0
        count2=0
        for i in range(len(s)):
            if s[i]=="0":
                count1+=1
                pre.append([count1,count2])
            elif s[i]=="1":
                count2+=1
                pre.append([count1,count2])
        pre.pop(0)
        new=[]
        for i in range(len(pre)):
            new.append([pre[i][0],pre[-1][1]-pre[i][1]])
        
        k=[]
        for i in range(len(pre)):
            k.append(sum(new[i]))
        k.pop(-1)
        
        return max(k)