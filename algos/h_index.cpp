#include <algorithm>
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(), less<>());
        int hindex=0;
        int currentCitations=0;
        int citsize = citations.size();
        for (int i=0;i<citations.size();i++) {
            currentCitations=citations[i];
            if (currentCitations>=citsize-i) {
                hindex= max(citsize-i, hindex);
            }
        }

        return hindex;
    }
};

int main() {
    vector<int> citations = {3,0,6,1,5};

    Solution s;
    cout << s.hIndex(citations) << endl;
    for (int i=0;i<citations.size();i++) {
        cout<<citations[i]<<endl;
    }

    return 0;
}