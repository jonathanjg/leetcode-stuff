#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> balloonMap;
        balloonMap['b'] = 1;
        balloonMap['a'] = 1;
        balloonMap['l'] = 2;
        balloonMap['o'] = 2;
        balloonMap['n'] = 1;

        unordered_map<char, int> textMap;

        for (int i=0;i<text.length();i++) {
            if (textMap.find(text[i]) == textMap.end()) {
               textMap[text[i]] = 1;
            }
            else {
                textMap[text[i]]++;
            }
        }

        int maxOccurence = text.length();
        for (char c:string("balloon")) {
            maxOccurence = min(maxOccurence, textMap[c]/balloonMap[c]);
        }
        return maxOccurence;
    }
};

int main() {
    Solution s;
    cout<<s.maxNumberOfBalloons("balloonballoon")<<endl;

    return 0;
}
