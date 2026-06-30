#include <iostream>
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

bool check(TreeNode* root, long long minimum, long long maximum) {

    if (root == NULL)
        return true;

    if (root->val <= minimum || root->val >= maximum)
        return false;

    return check(root->left, minimum, root->val) &&
           check(root->right, root->val, maximum);
}

bool isValidBST(TreeNode* root) {

    return check(root, LLONG_MIN, LLONG_MAX);
}

int main() {

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root))
        cout << "Valid BST";
    else
        cout << "Not a Valid BST";

    return 0;
}