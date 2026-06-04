#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int bestProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                bestProfit = max(bestProfit, prices[i] - minPrice);
            }
        }

        return bestProfit;
    }
};

int main() {

    vector<int> prices = {7,1,5,3,6,4};

    Solution obj;

    cout << obj.maxProfit(prices);

    return 0;
}