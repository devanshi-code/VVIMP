class Solution {
public:
    void findLeaf(TreeNode* root,vector<int>&leafsofT)
    {
        if(root==NULL) 
            return  ;
        if(root->left!=NULL) findLeaf(root->left,leafsofT);
        if(root->right!=NULL) findLeaf(root->right,leafsofT);
        if(root->left==NULL && root->right==NULL)
            leafsofT.push_back(root->val); //for pushing values of leafsofTrees
            
        
          
       
        // return;
    }    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafsofT1; //to store tree t1 values
        vector<int> leafsofT2; //to store tree t2 values
        findLeaf(root1,leafsofT1); //call function for T1
        findLeaf(root2,leafsofT2); //call function for T2
        return(leafsofT1==leafsofT2);
    }
};