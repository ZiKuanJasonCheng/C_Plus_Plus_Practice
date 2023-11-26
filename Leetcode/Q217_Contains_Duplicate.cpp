# include <iostream>
# include <vector>
# include <set>
using namespace std;

/* Leetcode Q217. Contains Duplicate */
/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            We use a set to keep unique elements. We then use a return object from an insert method to check if the inserted element has 
            already existed in the set.
        */

        set<int> myset;
        std::pair<set<int>::iterator, bool> ret;  // Will use its attribute to check if the inserted element is a duplicate

        for (int i=0; i<nums.size(); i++) {
            ret = myset.insert(nums[i]);
            if (ret.second == false) {  // If the element has already existed in the set, it will return false
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> case1{1, 2, 3, 1};
    vector<int> case2{1, 2, 3, 4};
    vector<int> case3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    vector<int> case4{6, 1, 3, 2, 4, 7};
    vector<int> case5{3, 8, 1, 4, 7, 5};
    vector<int> case6{2, 1, 2, 1, 0, 1, 2};

    Solution *solution;
    bool result;
    result = solution -> containsDuplicate(case1);
    cout << result << endl;
    result = solution -> containsDuplicate(case2);
    cout << result << endl;
    result = solution -> containsDuplicate(case3);
    cout << result << endl;
    result = solution -> containsDuplicate(case4);
    cout << result << endl;
    result = solution -> containsDuplicate(case5);
    cout << result << endl;
    result = solution -> containsDuplicate(case6);
    cout << result << endl;
}