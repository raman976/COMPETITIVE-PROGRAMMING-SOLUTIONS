class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        def merge_sorted_arrays(arr1, arr2):
            n, m = len(arr1), len(arr2)
            i, j = 0, 0
            merged = []
            while i < n and j < m:
                if arr1[i] <= arr2[j]:
                    merged.append(arr1[i])
                    i += 1
                else:
                    merged.append(arr2[j])
                    j += 1
            while i < n:
                merged.append(arr1[i])
                i += 1
            while j < m:
                merged.append(arr2[j])
                j += 1
            return merged
        merged=merge_sorted_arrays(nums1[:m],nums2)
        for i in range(len(merged)):
            nums1[i]=merged[i]