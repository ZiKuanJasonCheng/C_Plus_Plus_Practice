# include <iostream>
# include <vector>
# include <set>
using namespace std;

/* Leetcode Q15: 3Sum */
/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
   Notice that the solution set must not contain duplicate triplets. "".
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec_vec;
        set<vector<int>> set_vec;

        // We sort the vector so as to do the following O(N^2) iterations
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0; i<n-2; i++) {
            // i acts as a pivot index
            int low = i+1, high = n-1;
            while (low < high) {
                if (nums[i] + nums[low] + nums[high] < 0) {
                    low++;
                }
                else if (nums[i] + nums[low] + nums[high] > 0) {
                    high--;
                }
                else {
                    set_vec.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }

            // We don't use the following scripts because having the above loop included, the time complexity will be O(N^3), which will cause execution timeout
            // for(int j=i+1; j<nums.size()-1; j++) {
            //     for(int k=j+1; k<nums.size(); k++) {
            //         if( (nums[i] + nums[j] + nums[k]) == 0) {
            //             vector<int> vec;
            //             vec.push_back(nums[i]);
            //             vec.push_back(nums[j]);
            //             vec.push_back(nums[k]);
                        
            //             set_vec.insert(vec);
            //         }
            //     }
            // }
        }

        for (auto v: set_vec) {
            vec_vec.push_back(v);
        }

        return vec_vec;
    }
};

int main() {
    vector<int> case1 = {-1, 0, 1, 2, -1, -4};
    vector<int> case2 = {0, 1, 1};
    vector<int> case3 = {0, 0, 0};

    Solution *solution;

    vector<vector<int>> result1 = solution -> threeSum(case1);
    cout << "result1: " << endl;
    for (auto v: result1) {
        for (auto ele: v) {
            cout << ele << ", ";
        }
        cout << endl;
    }

    vector<vector<int> > result2 = solution -> threeSum(case2);
    cout << "result2: " << endl;
    for (auto v: result2) {
        for (auto ele: v) {
            cout << ele << ", ";
        }
        cout << endl;
    }

    vector<vector<int> > result3 = solution -> threeSum(case3);
    cout << "result3: " << endl;
    for (auto v: result3) {
        for (auto ele: v) {
            cout << ele << ", ";
        }
        cout << endl;
    }
}