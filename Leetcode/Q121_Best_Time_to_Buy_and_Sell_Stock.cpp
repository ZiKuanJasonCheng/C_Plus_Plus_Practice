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
            Because Leetcode does not allow O(n^2) solution to this problem, we have to find another faster solution.
            This solution costs only O(n) time complexity.
            There is only one correct maximal profit. However, there may be more than one possibilities of buy day and sell day
        */

        int curMax = 0;  // Used to keep current maximal profit. The lowest profit is 0 as default.
        int buy_day = 0;  // Used to keep current buy day
        int sell_day = 1;  // Used to keep current sell day

        for (int i=1; i < prices.size(); i++) {  // Iterate over all days to find a new buy day and sell day
            if (prices[i] > prices[buy_day]) {  // If price of current (i-th) day is higher than our expected buy day, this day may become a new sell day
                if (prices[i] - prices[buy_day] > curMax) {  // If new profit is higher than our current maximal profit, we update our profit and sell day
                    sell_day = i;
                    curMax = prices[i] - prices[buy_day];
                }
            }
            else {  // prices[i] <= prices[buy_day]
                // Because the price of current (i-th) day is less than our expected buy day, 
                // it's better to update our expected buy day to current (i-th) day
                buy_day = i;
            }
        }

        // Let's print an answer as well as buy day and sell day
        cout << "Maximal profit: " << curMax << ", buy_day: " << buy_day << ", sell_day: " << sell_day << endl;

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