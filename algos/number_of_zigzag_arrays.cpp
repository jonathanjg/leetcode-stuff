#include <iostream>
#include <vector>
using namespace std;

// NOT OWN SOLUTION
class Solution {
public:

    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;

        vector<long long> up(m+1, 0);
        vector<long long> down(m+1, 0);

        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m + 1, 0);
            vector<long long> newDown(m + 1, 0);

            long long prefix = 0;

            // newUp[x] = sum down[y] where y < x
            for (int x = 1; x <= m; x++) {
                newUp[x] = prefix;
                prefix = (prefix + down[x]) % MOD;
            }

            long long suffix = 0;

            // newDown[x] = sum up[y] where y > x
            for (int x = m; x >= 1; x--) {
                newDown[x] = suffix;
                suffix = (suffix + up[x]) % MOD;
            }

            up = newUp;
            down = newDown;
        }

        long long answer = 0;

        for (int x = 1; x <= m; x++) {
            answer = (answer + up[x] + down[x]) % MOD;
        }

        return answer;




    }
};

int main() {
    return 0;
}