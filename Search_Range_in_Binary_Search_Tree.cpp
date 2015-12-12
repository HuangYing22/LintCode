//Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
//Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. 
//Return all the keys in ascending order.
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(!st.empty() || (cur != NULL)) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if((cur->val >= k1) && (cur->val <= k2)) {
                    res.push_back(cur->val);
                }
                cur = cur->right;
            }
        }
        return res;
    }
};
