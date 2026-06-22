#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;

        for (int i=0; i<nums.size(); i++) {
            if (i>maxJump) {
                return false;
            }

            maxJump = max(maxJump, i+nums[i]);

            if (maxJump >= nums.size() -1) {
                return true;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.canJump(nums);
    return 0;
}