class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int profit = 0;
        for (int i=1;i<prices.size();i++){
            int price = prices[i] - low;
            profit = max(profit,price);
            low = min(prices[i],low);
        }
        return profit;
    }
};