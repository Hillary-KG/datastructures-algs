class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        left, right, maxProfit = 0, 1, 0
        while right < len(prices):
            # get price difference i.e is the transaction profitable
            profit = prices[right] - prices[left]
            if profit > 0:
                maxProfit = max(maxProfit, profit)
            else:
                left = right
            right += 1

        return maxProfit


#2 
class SolutionII(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        profit, buyDay = 0, 0
        
        for i in xrange(len(prices)):
            if (prices[i] - prices[buyDay]) > profit: 
                profit = prices[i] - prices[buyDay]
            elif prices[i] < prices[buyDay]: buyDay = i
        
        return profit