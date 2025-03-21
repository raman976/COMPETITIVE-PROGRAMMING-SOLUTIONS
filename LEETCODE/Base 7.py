####################################################################
####################################################################
'''
504. Base 7
Solved
Easy
Topics
Companies

Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"

Example 2:

Input: num = -7
Output: "-10"

 

Constraints:

    -107 <= num <= 107
'''
####################################################################
'''
link to the problem======>(https://leetcode.com/problems/base-7/)
'''
####################################################################

class Solution:
    def convertToBase7(self, num: int) -> str:
        flag=False
        if num==0:
            return "0"
        ans=""
        if num<0:
            flag=True
        num=abs(num)
        while num:
            num, m = num//7,num%7
            ans+=str(m)
        if flag:
            ans+="-"
        return ans[::-1]