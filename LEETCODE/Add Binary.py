##################################
"""
##################################
Add Binary
Solved
Easy
Topics
Companies

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


##################################
"""
##################################



class Solution:
    def addBinary(self, a: str, b: str) -> str:
        suma=0
        sumb=0
        for i in range(len(a)-1,-1,-1):
            suma+=int(a[i])*2**(len(a)-i)
        for i in range(len(b)-1,-1,-1):
            sumb+=int(b[i])*2**(len(b)-i)
        n=suma+sumb
        if n==0:
            return "0"
        p=[]
        while n!=0:
            p.append(n%2)
            n//=2
        p.reverse()
        p.pop()
        s=""
        for i in p:
            s+=str(i)
        return s

        