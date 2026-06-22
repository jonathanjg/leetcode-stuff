#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> count;
        for (int i=0; i<nums.size(); i++) {
            count[nums[i]] = count[nums[i]] + 1;
            if (count[nums[i]] > n) {
                return nums[i];
            }
        }
        return 0;
    }

    int majorityElement_slow(vector<int>& nums) {
        int n = (nums.size()/2);
        int majorityElement;
        for (int i=0; i<nums.size(); i++) {
            int currentMajority = 1;
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    currentMajority++;
                }
            }
            if (currentMajority > n) {
                majorityElement = nums[i];
            }
        }
        return majorityElement;
    }
};


int main() {
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}
