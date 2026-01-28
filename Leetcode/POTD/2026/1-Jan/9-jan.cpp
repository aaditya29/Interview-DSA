// leetcode 865. Smallest Subtree with all the Deepest Nodes
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getDepth(TreeNode *node)
    {
        if (node == NULL)
            return 0;

        return 1 + max(getDepth(node->right), getDepth(node->left));
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        int rightDepth = getDepth(root->right);
        int leftDepth = getDepth(root->left);

        if (rightDepth == leftDepth)
            return root;
        else if (rightDepth > leftDepth)
            return subtreeWithAllDeepest(root->right);
        else
            return subtreeWithAllDeepest(root->left);
    }
};