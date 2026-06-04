#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int best = nums[0];
    int running = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        running = max(nums[i], running + nums[i]);

        if (running > best) {
            best = running;
        }
    }

    return best;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum Subarray Sum = " << maxSubArray(nums) << endl;

    return 0;
}