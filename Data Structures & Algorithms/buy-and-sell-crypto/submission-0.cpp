class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprices = prices[0];
        int maxprofit = 0;
        for(int i =0; i<prices.size();i++){
            int profit = prices[i]-minprices;
            if(profit > maxprofit){
                maxprofit =  profit;
            }
            if(prices[i] < minprices){
                minprices = prices[i];
            }
        }
        return maxprofit;
    }
};
