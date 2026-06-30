#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {

        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {

            TreeNode* node = q.front();
            q.pop();

            int index;

            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;

            level[index] = node->val;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        ans.push_back(level);
        leftToRight = !leftToRight;
    }

    return ans;
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);

    for (auto level : result) {
        cout << "[ ";
        for (int value : level)
            cout << value << " ";
        cout << "]" << endl;
    }

    return 0;
}