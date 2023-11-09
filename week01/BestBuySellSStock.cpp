// TC: O(N)
// MC: O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,maxP=0;
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
               l=r;
            }
            r+=1;
        }
        return maxP; 
    }
};
