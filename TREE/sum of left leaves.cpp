class Solution {
public:
    int sum(TreeNode* root,bool onleaves)
    {   if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL)
            return onleaves?root->val:0;
        int leftAns=sum(root->left,true);
        int rightAns=sum(root->right,false);
        return leftAns+rightAns;
    }    
    int sumOfLeftLeaves(TreeNode* root) {
        
       return sum(root,false);
       
    }
};