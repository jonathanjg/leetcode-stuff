#include <iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        for (int i =0; i < prices.size(); i++) {
            int currentProfit = 0;
            for (int j = i+1; j < prices.size(); j++) {
                currentProfit = prices[j]-prices[i];
                result = max(0,max(result, currentProfit));
            }
        }
        return result;
    }

    int maxProfit_better(vector<int>& prices) {
        int minPrice = prices[0];
        int bestProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            bestProfit = max(bestProfit, prices[i]-minPrice);
        }
        return bestProfit;
    }

};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices);
    return 0;
}