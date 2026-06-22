#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
                vector<int> copynums = nums;
                for (int i=0; i<nums.size(); i++) {
                    nums[(i+k) % nums.size()]=copynums[i];

                }
    }

    void rotate_constant_space(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

int main() {
    vector<int> nums = {1,2};
    Solution s;
    s.rotate_constant_space(nums, 2);
    for (int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<endl;
    }

    return 0;
}