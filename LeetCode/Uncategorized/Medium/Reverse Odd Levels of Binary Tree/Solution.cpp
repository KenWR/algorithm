//

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
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> dq;
        int level = 0;

        dq.push_back(root);
        while(!dq.empty()) {
            int dqSize = dq.size();

            // swap node val when level is odd
            if (level % 2) {
                for(int i = 0, j = dqSize - 1; i < j; i++, j--) {
                    swap(dq[i]->val, dq[j]->val);
                }
            }

            // fill deque by next level
            while(dqSize) {
                TreeNode* node = dq.front();
                dq.pop_front();

                if (node->left) {
                    dq.push_back(node->left);
                    dq.push_back(node->right);
                }
                
                dqSize--;
            }
            level++;
        }

        return root;
    }
};