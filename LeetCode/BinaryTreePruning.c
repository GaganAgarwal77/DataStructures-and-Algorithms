/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */




struct TreeNode* pruneTree(struct TreeNode* root)
{
        if(root != NULL)
        {
            if(root->left != NULL)
                root->left = pruneTree(root->left);
            if(root->right != NULL)
                root->right = pruneTree(root->right);
            if(root->val == 0)
            {    
                if(root->left == NULL && root->right == NULL)
                    return NULL;
            }
            return root;              
        }   
        else
        {
            return NULL;
        }
}