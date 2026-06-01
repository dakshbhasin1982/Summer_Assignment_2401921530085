#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> storedValues;

        for (int index = 0; index < nums.size(); index++) {

            int neededNumber = target - nums[index];

            if (storedValues.find(neededNumber) != storedValues.end()) {

                return {storedValues[neededNumber], index};
            }

            storedValues[nums[index]] = index;
        }

        return {};
    }
};