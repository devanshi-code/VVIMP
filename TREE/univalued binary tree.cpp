
class Solution {
public:
    bool isUnivalued(TreeNode *root,int val)
    {
        if(root == NULL)
            return true;
        if(root->val!=val)
            return false;
        bool leftAns= isUnivalued(root->left,val);
        bool rightAns= isUnivalued(root->right,val);
        return leftAns && rightAns;
    }    
    bool isUnivalTree(TreeNode* root) {
        return isUnivalued(root,root->val); /* two arguments are value of root and value that need to be compared*/
    }
};