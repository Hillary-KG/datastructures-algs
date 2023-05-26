# class Solution:
#     def productOfArrayExceptSelf(nums):
#         res = [1] * len(nums)
#         prefix = 1
#         for i in range(len(nums)):
#             res[i] *= prefix
#             prefix = 



class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []

        for i, n in enumerate(nums):
            while nums[i] != n:
                result[i] *= n

        return result

if __name__ == "__main__":
    prdct = Solution()
    inp = [1,2,3,4]
    res = prdct.productExceptSelf(inp)
    print(res)
    