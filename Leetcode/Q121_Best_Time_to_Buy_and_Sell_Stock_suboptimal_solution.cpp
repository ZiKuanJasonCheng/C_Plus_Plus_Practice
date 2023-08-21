# include <iostream>
# include <vector>
using namespace std;

/* Leetcode Q121: Best Time to Buy and Sell Stock */
/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
   You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
   Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            Although the following solution is correct, its time complexity is O(n^2), which will cause excess of memory limitation.
            There is only one correct maximal profit. However, there may be more than one possibilities of buy day and sell day.
        */

        int curMax = 0;  // Used to keep current maximal profit. The lowest profit is 0 as default.
        for (int i=0; i < prices.size()-1; i++) {  // Iterate over all possible buy days
            for (int j=i+1; j < prices.size(); j++) {  // Iterate over all possible sell days
                if (prices[j] - prices[i] > curMax) {  // If new profit is higher than our current maximal profit, we update our profit
                    curMax = prices[j] - prices[i];
                }
            }
        }

        return curMax;
    }
};

int main() {
    vector<int> case1{7, 1, 5, 3, 6, 4};
    vector<int> case2{7, 6, 4, 3, 1};
    vector<int> case3{3, 7, 2, 1, 4, 6, 5};
    vector<int> case4{6, 1, 3, 2, 4, 7};
    vector<int> case5{3, 8, 1, 4, 7, 5};
    vector<int> case6{2, 1, 2, 1, 0, 1, 2};

    Solution *solution;
    solution -> maxProfit(case1);
    solution -> maxProfit(case2);
    solution -> maxProfit(case3);
    solution -> maxProfit(case4);
    solution -> maxProfit(case5);
    solution -> maxProfit(case6);
}