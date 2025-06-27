# Write a program that takes an array denoting the daily stock price, and retums the maximum profit
# that could be made by buying and then selling one share of that stock. There is no need to buy if
# no profit is possible.

def buy_stocks(prices):
    if not prices:
        return 0
    
    max_profit, min_price_so_far = 0.0, float('inf')
    for price in prices:
        max_profit_sell_today = price - min_price_so_far
        max_profit = max(max_profit, max_profit_sell_today)
        min_price_so_far = min(price, min_price_so_far)
    return max_profit

# test
if __name__ == "__main__":
    prices = [43,42,43,45,49,52,51,52,50,50,49,48,54,53,52,53]
    max_profit = buy_stocks(prices)
    print(max_profit)

    
