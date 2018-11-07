class Solution {
public:
    /** 
     * Say you have an array for which the ith element is the price of
     * a given stock on day i.
     * If you were only permitted to complete at most one transaction 
     * (i.e., buy one and sell one share of the stock), design an algorithm
     * to find the maximum profit.
     * 
     * Note that you cannot sell a stock before you buy one.
     */
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0], max_profit = 0;
        for (auto& price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};
