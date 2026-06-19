#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int next_free_index = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                nums[next_free_index] = nums[i];
                next_free_index++;
            }
        }
        return next_free_index;
    }
};

int main() {

    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << s.removeElement(nums, 2) << endl;

    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}