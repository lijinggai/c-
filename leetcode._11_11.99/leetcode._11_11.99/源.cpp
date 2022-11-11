class Solution {
public:
    TreeNode* compare = nullptr; TreeNode* node1 = nullptr; TreeNode* node2 = nullptr;
    void _recoverTree(TreeNode* root)
    {
        if (root == nullptr)    return;
        _recoverTree(root->left);
        //���������������������������
        if (compare != nullptr && node1 == nullptr && compare->val > root->val)
            node1 = compare;
        if (compare != nullptr && node1 != nullptr && compare->val > root->val)
            node2 = root;
        compare = root;
        _recoverTree(root->right);
    }
    void recoverTree(TreeNode* root) {
        _recoverTree(root);
        swap(node1->val, node2->val);
    }
};