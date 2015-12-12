//Remove Node in Binary Search Tree
//Given a root of Binary Search Tree with unique value for each node.  
//Remove the node with given value. 
//If there is no such a node with given value in the binary search tree, do nothing. 
//You should keep the tree still a binary search tree after removal.
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(root == NULL) return root;
        
        TreeNode* dummyNode = new TreeNode(0);
        dummyNode->right = root;
        TreeNode* cur = root;
        TreeNode* pre = dummyNode;
        //if cur is at the right of pre
        bool atRgt = true;
        
        while(cur != NULL) {
            if(cur->val == value) {
                if(cur->left == NULL) {
                    if(atRgt) {
                        pre->right = cur->right;
                    } else {
                        pre->left = cur->right;
                    }
                    delete(cur);
                    return dummyNode->right;
                }
                
                if(cur->right == NULL) {
                    if(atRgt) {
                        pre->right = cur->left;
                    } else {
                        pre->left = cur->left;
                    }
                    delete(cur);
                    return dummyNode->right;
                }

                TreeNode* preMove = NULL;
                TreeNode* move = findLeftMost(cur->right, preMove);
                TreeNode* moveRgt = move->right;

                if(atRgt) {
                    pre->right = move;
                } else {
                    pre->left = move;
                }
                move->right = cur->right;
                move->left = cur->left;
                
                //move might be cur->right (cur->right->left == NULL)
                //preMove could be NULL
                if(preMove != NULL) {       
                    preMove->left = moveRgt;
                }
                delete(cur);
              
                return dummyNode->right;
            }
            
            pre = cur;
            if(cur->val > value) {
                cur = cur->left;
                atRgt = false;
            } else {
                cur = cur->right;
                atRgt = true;
            }
        }
        
        return dummyNode->right;
    }
    
    //想要额外return一个TreeNode*的时候可以把TreeNode*&作为参数传进去
    TreeNode* findLeftMost(TreeNode* root, TreeNode*& pre) {
        if(root == NULL) {
            pre = NULL;
            return NULL;
        }
        while(root->left != NULL) {
            pre = root;
            root = root->left;
        }
        return root;
    }

};
