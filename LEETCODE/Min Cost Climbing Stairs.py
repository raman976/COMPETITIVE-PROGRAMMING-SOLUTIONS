#######################################################################
#######################################################################
'''
Accepted
Accepted
Editorial
Editorial
Solutions
Solutions
Submissions
Submissions
Code
Testcase
Testcase
Test Result
Note
Note
746. Min Cost Climbing Stairs
Solved
Easy
Topics
Companies
Hint

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

 

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999
'''
#######################################################################
#######################################################################

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dictn={}
        def f(a,n,ind):
            if ind in dictn:
                return dictn[ind]
            if ind>n-1:
                return 0
            else:
                case1=a[ind]+f(a,n,ind+1)
                case2=a[ind]+f(a,n,ind+2)
                dictn[ind]=min(case1,case2)
            return dictn[ind]
        return min((f(cost,len(cost),1),f(cost,len(cost),0)))