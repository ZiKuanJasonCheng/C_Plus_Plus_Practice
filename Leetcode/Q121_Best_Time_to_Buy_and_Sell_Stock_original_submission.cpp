class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int curMax = 0;
        //int bestBuy = -1;
        //int bestSell = -1;
        int N = prices.size();
        cout << "N: " << N << endl;

        //int arr_cum_diff[N][N] = {0};  // https://en.cppreference.com/w/c/language/array_initialization
        //vector<vector<int>> arr_cum_diff;

        if (N == 1) {
            return 0;
        }
        else if (N == 2) {
            if (prices[1] - prices[0] >= 0) {
                return prices[1] - prices[0];
            }
            else {
                return 0;
            }
        }
        

        // --- The folllowing will cause wrong answer
        /*
        int *mat_cum_diff = new int[(N-1)*(N-1)];
        vector<int> diff;
        for (int i=0; i < N-1; i++) {
            diff.push_back(prices[i+1] - prices[i]);
            for (int j=0; j < N-1; j++) {
                if (i == j) {
                    mat_cum_diff[i*(N-1)+i] = prices[i+1] - prices[i];
                }
                else {
                    mat_cum_diff[i*(N-1)+j] = 0;
                }
            }
        }

        int i = N / 2 - 1;
        cout << "i: " << i << endl;
        int diff_begin = i, diff_end=i;
        int j = i + 1;
        int init_diff = diff[i];

        for (auto d: diff) {
            cout << "d: " << d << endl;
        }
        // Ex: diff = {-6, 4, -2, -1, 2, -4, 3, -2}, {-1, -2, -1, -2}

        // This might happen upon initialization
        if (init_diff <= 0) {
            while (i >= 0 || j < diff.size()) {
                if (diff[i] > 0 && diff[i] >= diff[j]) {
                    init_diff = diff[i];
                    //buy_day = i;
                    //sell_day = buy_day + 1;
                    diff_end = diff_begin = i;
                    break;
                }
                else if (diff[j] > 0 && diff[j] >= diff[i]) {
                    init_diff = diff[j];
                    //buy_day = j;
                    //sell_day = buy_day + 1;
                    diff_end = diff_begin = j;
                    break;
                }
                else {
                    i--;
                    j++;
                }
            } 
        }
        if (init_diff <= 0) {
            return 0;
        }

        cout << "diff_begin: " << diff_begin << endl;
        i = diff_begin;
        j = i;
        int buy_day = i, sell_day = buy_day + 1;
        int curMax = diff[diff_begin];
        cout << "curMax: " << curMax << endl;
        bool day_changed = false;
        while (i-1 >= 0 || j+1 < diff.size()) {
            if (i-1 >= 0) {
                //mat_cum_diff[i][sell_day-1] =  mat_cum_diff[i+1][sell_day-1] + diff[i];
                mat_cum_diff[(i-1)*(N-1)+sell_day-1] = mat_cum_diff[i*(N-1)+sell_day-1] + diff[i-1];
                cout << "i: " << i << ", sell_day: " << sell_day << ", ("<<i<<", "<<sell_day-1<<"): "<< mat_cum_diff[i*(N-1)+sell_day-1] << ", diff["<<i-1<<"]: "<< diff[i-1] << ", ("<<i-1<<", "<<sell_day-1<<"): "<< mat_cum_diff[(i-1)*(N-1)+sell_day-1] << endl;
                if (diff[i-1] + mat_cum_diff[i*(N-1)+sell_day-1] > curMax) {  //mat_cum_diff[i][sell_day-1]
                    buy_day = i-1;
                    curMax = diff[i-1] + mat_cum_diff[i*(N-1)+sell_day-1];  //mat_cum_diff[i][sell_day-1]
                    cout << "Buy day is changed. buy_day: " << buy_day << ", curMax: " << curMax << endl;
                    day_changed = true;
                }
            }
            if (j+1 < diff.size()) {
                //mat_cum_diff[buy_day][j] =  mat_cum_diff[buy_day][j-1] + diff[j];
                mat_cum_diff[buy_day*(N-1)+(j+1)] = mat_cum_diff[buy_day*(N-1)+j] + diff[j+1];
                cout << "j: " << j << ", buy_day: " << buy_day << ", ("<<j<<", "<<buy_day<<"): "<< mat_cum_diff[buy_day*(N-1)+j] << ", diff["<<j+1<<"]: "<< diff[j+1] << ", ("<<j+1<<", "<<buy_day<<"): "<< mat_cum_diff[buy_day*(N-1)+(j+1)] << endl;
                if (diff[j+1] + mat_cum_diff[buy_day*(N-1)+j] > curMax) {  //mat_cum_diff[buy_day][j]
                    sell_day = j+2;
                    curMax = diff[j+1] + mat_cum_diff[buy_day*(N-1)+j];
                    cout << "Sell day is changed. sell_day: " << sell_day << ", curMax: " << curMax << endl;
                    day_changed = true;
                }
            }

            if (!day_changed) {
                i--;
                j++;
            }
            else{
                day_changed = false;
            }
            
            
        }
        cout << "Final: buy_day: " << buy_day << ", sell_day: " << sell_day << endl;
        */
        // ---


        // --- The following will cause excess of memory limitation
        /*
        int *mat_price_diff = new int[N*N];
        int curMax = 0;
        int max_price = prices[0];
        int max_day = 0;
        int min_price = prices[0];
        int min_day = 0;
        for (int i=0; i < N; i++) {
            if (prices[i] > max_price) {
                max_price = prices[i];
                max_day = i;
            }
            if (prices[i] < min_price) {
                min_price = prices[i];
                min_day = i;
            }
        }

        if (max_day > min_day) {
            return max_price - min_price;
        }

        for (int i=0; i < N; i++) {
            if ( (prices[i] > min_price) && (i > min_day) || (i == max_day) ) {
                // This day is impossible to be the buy day, so we skip the rest of the process in this loop
                continue;
            }
            for (int j=i+1; j < N; j++) {
                if ( (prices[i] > min_price) && (j == min_day) ) { 
                    // We don't have to do the rest of the process because the maximun profit won't happen if the buy day is i and the sell day is >= j, because otherwise the buy day will not be i but other day, perhaps j
                    continue;
                }
                else if (prices[j] - prices[i] > curMax) {
                    curMax = prices[j] - prices[i];
                }
            }
        }*/
        // ---


        // --- The following will cause excess of memory limitation
        // for (int j=i; j < N; j++) {
        //         if (i == j) {
        //             mat_cum_diff[i*(N-1)+j] = prices[j+1] - prices[j];
        //         }
        //         else {
        //             mat_cum_diff[i*(N-1)+j] = mat_cum_diff[i*(N-1)+(j-1)] + prices[j+1] - prices[j];
        //         }

        //         if (mat_cum_diff[i*(N-1)+j] > curMax) {
        //             curMax = mat_cum_diff[i*(N-1)+j];
        //         }
        // }
        // ---

        int curMax = 0;
        int buy_day = 0;
        int sell_day = 1;
        for (int i=1; i < N; i++) {
            if (prices[i] > prices[buy_day]) {
                if (prices[i] - prices[buy_day] > curMax) {
                    sell_day = i;
                    curMax = prices[i] - prices[buy_day];
                }
            }
            else {
                buy_day = i;
            }

        }

        return curMax;
    }
};