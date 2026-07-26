class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0];
        int maxi = 0;
        for (int i=1;i<prices.size();i++){
            lowestPrice = min(lowestPrice,prices[i]);
            maxi = max(maxi,prices[i]-lowestPrice);
        }
        //if (maxi == INT_MIN) return 0;
        return maxi;
    }
};