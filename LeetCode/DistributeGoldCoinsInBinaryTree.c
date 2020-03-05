/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node,int* moves)
{
    if(node == NULL)
        return 0;
    
    int L = dfs(node->left,moves);
    int R = dfs(node->right,moves);
    *moves += abs(L) + abs(R);
    return node->val + L + R - 1;

}


int distributeCoins(struct TreeNode* root){

    int ans = 0;
    dfs(root,&ans);
    return ans;
}

