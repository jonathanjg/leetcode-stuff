#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1.resize(m);
        // //nums2.resize(n); // prob not neccesary
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        //
        //
        // int size = nums1.size();
        // int lsize = size / 2;
        // int rsize = size - lsize;
        //
        // // temp vectors
        vector<int> L(m), R(n);

        for (int i = 0; i < m; i++) {
            L[i] = nums1[i];
        }
        for (int i = 0; i < n; i++) {
            R[i] = nums2[i];
        }

        int i = 0, j = 0, k = 0;

        while (i<m && j<n) {
            if (L[i] <= R[j]) {
                nums1[k] = L[i];
                i++;
            }
            else {
                nums1[k] = R[j];
                j++;
            }

            k++;
        }

        while (i<m) {
            nums1[k] = L[i];
            i++;
            k++;
        }

        while (j<n) {
            nums1[k] = R[j];
            j++;
            k++;
        }


    }
};


int main() {
    vector<int> nums1 = {4,0,0,0,0,0};
    int m = 1;
    vector<int> nums2 = {1,2,3,5,6};
    int n = 5;
    Solution s;
    s.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}