#include <iostream>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

bool validate(TreeNode* root,
              long long minVal,
              long long maxVal) {

    if(root == NULL) {
        return true;
    }

    if(root->val <= minVal ||
       root->val >= maxVal) {
        return false;
    }

    return validate(root->left,
                    minVal,
                    root->val)

           &&

           validate(root->right,
                    root->val,
                    maxVal);
}

bool isValidBST(TreeNode* root) {

    return validate(root,
                    LLONG_MIN,
                    LLONG_MAX);
}

int main() {

    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if(isValidBST(root))
        cout << "Valid BST";
    else
        cout << "Invalid BST";

    return 0;
}