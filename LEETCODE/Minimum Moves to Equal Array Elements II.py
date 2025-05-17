class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        arr=nums
        arr.sort()
        n=len(nums)
        median = arr[n // 2]
        cost = sum(abs(x - median) for x in arr)
        return cost