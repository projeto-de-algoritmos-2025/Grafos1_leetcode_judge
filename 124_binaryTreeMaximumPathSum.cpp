// Autor: Lívia Rodrigues Reis - 180105051
// Leetcode Hard :: 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum;

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }

private:
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        int sum = root->val + left + right;
        maxSum = max(maxSum, sum);

        return max(left, right) + root->val;
    }
};
