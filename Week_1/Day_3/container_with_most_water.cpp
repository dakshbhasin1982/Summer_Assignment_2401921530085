#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

int maxWater(vector<int>& height) {

    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while(left < right) {

        int width = right - left;
        int currentHeight = min(height[left], height[right]);
        int currentArea = width * currentHeight;

        if(currentArea > maxArea) {
            maxArea = currentArea;
        }

        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}
int main() {

    int n;
    cin >> n;

    vector<int> height(n);

    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << "Maximum water that can be contained: " << maxWater(height) << endl;

    return 0;
}
