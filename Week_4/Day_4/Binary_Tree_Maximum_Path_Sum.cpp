 #include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int maximumSum = INT_MIN;

int dfs(TreeNode* root) {

    if (root == NULL)
        return 0;

    int left = max(0, dfs(root->left));
    int right = max(0, dfs(root->right));

    maximumSum = max(maximumSum,
                     left + right + root->val);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {

    dfs(root);

    return maximumSum;
}

int main() {

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Path Sum = "
         << maxPathSum(root);

    return 0;
}