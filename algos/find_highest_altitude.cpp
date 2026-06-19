#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;
        for (int i = 0; i < gain.size(); ++i) {
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }
        return maxAltitude;
    }
};

int main() {
    Solution s;
    int gain[5] = {-5, 1, 5, 0, -7};
    vector<int> gain_vector = {-5, 1, 5, 0, -7};

    cout << s.largestAltitude(gain_vector) << endl;
    return 0;
}