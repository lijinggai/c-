class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int LevelSize = 0;
        if (root)
        {
            //��һ��һ��Ϊ1
            q.push(root);
            LevelSize = 1;
        }
        vector<vector<int>> vv;
        while (!q.empty())
        {
            vector<int> v;
            //����һ��һ�������
            for (int i = 0; i < LevelSize; i++)
            {
                TreeNode* front = q.front();
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
                v.push_back(q.front()->val);
                q.pop();
            }
            vv.push_back(v);
            //��һ����꣬��һ�����꣬����Ϊ���е�size
            LevelSize = q.size();
        }
        return vv;
    }
};