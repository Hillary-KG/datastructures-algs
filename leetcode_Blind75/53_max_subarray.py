class Solution(object):
    def maxSubArray(self, nums):
        maxSubArray = []
        curSum = 0
        for i in range(len(nums)):
            if nums[i] > 0:
                curSum += nums[i]
                maxSubArray.append(nums[i])
        return maxSubArray, curSum



if __name__ == "__main__":
    prdct = Solution()
    inp = [-2,1,-3,4,-1,2,1,-5,4]
    res = prdct.maxSubArray(inp)
    print(res)

    