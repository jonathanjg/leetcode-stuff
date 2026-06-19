#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }

            }
            else if (s[i] == '#') {
                result = result.append(result);
            }
            else if (s[i] == '%') {
                reverse(result.begin(), result.end());
            }
            else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};



int main() {
    Solution s;
    string testString = "*%";
    cout << s.processStr(testString) << endl;
    return 0;
}