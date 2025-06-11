#########################################
#########################################
'''
461. Hamming Distance
Solved
Easy
Topics
premium lock iconCompanies

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:

Input: x = 3, y = 1
Output: 1

 

Constraints:

    0 <= x, y <= 231 - 1

 

Note: This question is the same as 2220: Minimum Bit Flips to Convert Number.
'''
#########################################
#########################################

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        num1=bin(x)
        num2=bin(y)
        num1=(num1[2:])
        num2=(num2[2:])
        a=abs(len(num1)-len(num2))
        if (len(num1)<len(num2)):
            num1="0"*(a)+num1
        else:
            num2="0"*(a)+num2
        count=0
        for i in range(len(num1)):
            if num1[i]!=num2[i]:
                count+=1
        return count
    
