class Solution:
    def coinChange(self, coins: list, amount: int) -> int:
        result = [0]+[0xffffff]*amount
        for coin in coins:
            for i in range(1, amount+1):
                if i >=coin:
                    result[i] = min(result[i],result[i-coin]+1)
        if result[amount] == 0xffffff:
            return -1
        else: 
            return result[amount]
