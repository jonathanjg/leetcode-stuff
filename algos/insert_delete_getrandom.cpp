#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:

    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.find(val)!=mp.end()) {
            return false;
        }
        values.push_back(val);
        mp[val] = values.size()-1;

        return true;
    }

    bool remove(int val) {
        if (mp.find(val)==mp.end()) {
            return false;
        }

        int indexToRemove = mp[val];
        int lastValue = values.back();

        values[indexToRemove] = lastValue;
        mp[lastValue] = indexToRemove;

        values.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }

private:
    unordered_map<int,int> mp;
    vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    int param_3 = obj->getRandom();
    return 0;
}