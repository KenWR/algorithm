// Hash Map

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
private:
    int getMinimumSwaps(vector<int>& original) {
        vector<int> sorted = original;
        int size = original.size();
        int count = 0;

        sort(sorted.begin(), sorted.end());

        // set original array position
        unordered_map<int, int> pos;
        for (int i = 0; i < size; i++) {
            pos[original[i]] = i;
        }

        for (int i = 0; i < size; i++) {
            if (original[i] != sorted[i]) {
                count++;

                int curPos = pos[sorted[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }

        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        deque<TreeNode*> dq;
        int operations = 0;

        dq.push_back(root);
        while(!dq.empty()) {
            int dqSize = dq.size();

            // make values vector
            vector<int> values(dqSize);
            for (int i = 0; i < dqSize; i++) {
                TreeNode* left = dq.front()->left;
                TreeNode* right = dq.front()->right;
                values[i] = dq.front()->val;
                dq.pop_front();

                if (left)  dq.push_back(left);
                if (right) dq.push_back(right);
            }
            
            operations += getMinimumSwaps(values);
        }

        return operations;
    }
};