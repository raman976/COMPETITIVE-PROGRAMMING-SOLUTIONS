####################################################################
####################################################################
'''
3211. Generate Binary Strings Without Adjacent Zeros
Solved
Medium
Topics
Companies
Hint

You are given a positive integer n.

A binary string x is valid if all

of x of length 2 contain at least one "1".

Return all valid strings with length n, in any order.

 

Example 1:

Input: n = 3

Output: ["010","011","101","110","111"]

Explanation:

The valid strings of length 3 are: "010", "011", "101", "110", and "111".

Example 2:

Input: n = 1

Output: ["0","1"]

Explanation:

The valid strings of length 1 are: "0" and "1".

 

Constraints:

    1 <= n <= 18

'''
####################################################################
####################################################################

class Solution:
    def validStrings(self, n: int) -> List[str]:
        lis=[]
        for i in range(0,2**n):
            a=bin(i)
            b=a.index("b")
            k=a[b+1:]
            d='0'
            d="0"*(n-len(k))
            ans=d+k 
            if ans.count('00')>=1:
                continue
            else:
                lis.append(ans)
        return lis