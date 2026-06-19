#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next_free_index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[next_free_index-1]) {
                nums[next_free_index] = nums[i];
                next_free_index++;
            }

        }

        return next_free_index;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,5,5};
    cout << s.removeDuplicates(nums) << endl;
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}