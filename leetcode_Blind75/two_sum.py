class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_map = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in hash_map:
                return [hash_map[diff], i]
            hash_map[n] = i
        return