#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int leftMax = 0;
            int rightMax = 0;

            for (int j =0; j<=i;j++) {
                leftMax = max(leftMax,height[j]);
            }

            for (int j=i;j<n;j++) {
                rightMax = max(rightMax,height[j]);
            }
            result += min(leftMax,rightMax) - height[i];
        }
        return result;
    }
};


int main() {

    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;

    cout<<s.trap(height)<<endl;
    return 0;
}