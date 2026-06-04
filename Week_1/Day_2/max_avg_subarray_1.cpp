#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {

    long long windowSum = 0;

    for(int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    long long maxSum = windowSum;

    for(int i = k; i < nums.size(); i++) {
        windowSum += nums[i];
        windowSum -= nums[i - k];

        if(windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return (double)maxSum / k;
}

int main() {

    int n, k;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> k;

    cout << findMaxAverage(nums, k);

    return 0;
}