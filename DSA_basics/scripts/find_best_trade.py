# Your function should calculate the greatest profit that could be made from a single “buy” transaction followed by a single “sell” transaction.
# time complexity : o(n), space complexity : O(1)
import math
def find_best_trade(prices):
    min_price = prices[0]
    best_profit = 0
    for price in prices:
        if price <= min_price:
            min_price = price
        elif price - min_price >= best_profit:
            best_profit = price - min_price
    
    return best_profit

arr = [10, 7, 5, 8, 11, 2, 6]

print(find_best_trade(arr))

    