class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashNum={}
        for i in nums:
            if i not in hashNum:
                hashNum[i] = 1
            else:
                return True
        return False