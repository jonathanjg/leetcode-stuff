#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // this solution is O(n²)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int result = -1;

        for (int i = 0; i < n; i++) {
            bool canComplete = true;
            int currentGas = gas[i];
            for (int j = i; j < i+n; j++) {
                currentGas -= cost[j%n];
                if (currentGas < 0) {
                    canComplete = false;
                    break;
                }
                currentGas += gas[(j+1) % n];
            }
            if (canComplete) {
                result = i;
            }

        }

        return result;
    }

    int faster_canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currentGas = 0;
        int totalGas = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            totalGas += diff;
            currentGas += diff;
            if (currentGas < 0) {
                start = i+1;
                currentGas = 0;
            }
        }
        if (totalGas < 0) {
            return -1;
        }

        return start;



    }
};


int main() {

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    Solution s;
    cout<<s.canCompleteCircuit(gas, cost);
    return 0;
}