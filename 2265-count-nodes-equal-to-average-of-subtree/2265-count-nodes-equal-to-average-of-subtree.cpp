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
int ans=0;

pair<int,int> dfs(TreeNode* root)
{
    if(!root) return {0,0};
    auto left=dfs(root->left);
    auto right=dfs(root->right);

    int val=left.first+root->val+right.first;
    int llen=left.second;
    int rlen=right.second;
    int cnt=llen+rlen+1;
    int avg=(val/(cnt));

    if(root->val==avg) ans++;


    return {val,cnt};
}
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
        
    }
};