class Solution {
public:
    void rootToLeaf(TreeNode* root,string currentPath,int answer[])
    {   
        if(root->left== NULL && root->right== NULL)
            //change current path->binary string to decimal and add in answer
        {   currentPath+=to_string(root->val);
            answer[0]+=stoi(currentPath,0,2);
            return;
        }
        string curr=to_string(root->val);
        if(root->left!=NULL)
            rootToLeaf(root->left,currentPath +curr,answer);
        if(root->right!=NULL)
            rootToLeaf(root->right,currentPath + curr,answer);
        return;
    }    
    int sumRootToLeaf(TreeNode* root) {
        int* answer=new int[1];//dynamic allocation of memory
        answer[0]=0;
        rootToLeaf(root,"",answer);
        return answer[0];
    }
};