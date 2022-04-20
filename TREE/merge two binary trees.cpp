class Solution {
public:
  
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1,root2);
    }
   TreeNode* merge(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL)
            return root2;
        if(root2==NULL)
            return root1;
        TreeNode* newNode=new TreeNode(root1->val+root2->val);
        newNode->left=merge(root1->left,root2->left);
        newNode->right=merge(root1->right,root2->right);
        return newNode;
    }    
};