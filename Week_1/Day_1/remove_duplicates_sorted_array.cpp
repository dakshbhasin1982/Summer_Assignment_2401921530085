 #include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int uniqueIndex = 0;

        for (int currentIndex = 1; currentIndex < nums.size(); currentIndex++) {

            if (nums[currentIndex] != nums[uniqueIndex]) {

                uniqueIndex++;
                nums[uniqueIndex] = nums[currentIndex];
            }
        }

        return uniqueIndex + 1;
    }
};

int main() {

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Unique elements: " << k << endl;

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}