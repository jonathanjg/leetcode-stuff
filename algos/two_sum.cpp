#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j<nums.size(); j++) {
                if (nums[i] + nums [j] == target) {
                    solution.push_back(i);
                    solution.push_back(j);
                }
            }
        }
        return solution;
    }
};

// Use unordered_map since maps sorted key lookup time complexity is O(log n) compared to unordered map O(1)
class Solution_hash {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int neededNumber = target - currentNumber;

            if (mp.find(neededNumber) != mp.end()) {
                solution.push_back(i);
                solution.push_back(mp[neededNumber]);
            }
            mp[nums[i]] = i;
        }

        return solution;
    }
};




int main() {
    Solution_hash s;
    vector<int> nums = {2,5,3};
    vector<int> result = s.twoSum(nums, 5);
    for (int i: result) {
        cout << "index at " << i << " ";
    }
    return 0;
}