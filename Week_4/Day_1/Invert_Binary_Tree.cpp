#include <iostream>
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

TreeNode* invertTree(TreeNode* root) {

    if(root == NULL) {
        return NULL;
    }

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void inorder(TreeNode* root) {

    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Before Inversion: ";
    inorder(root);

    invertTree(root);

    cout << "\nAfter Inversion: ";
    inorder(root);

    return 0;
}