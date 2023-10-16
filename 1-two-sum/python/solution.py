class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for (i, n) in enumerate(nums):
            c = target - n;
            try:
                j = nums.index(c)
            except:
                continue
            if c in nums and i != j:
                return [i, j]
